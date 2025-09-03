# 13.5 Signal Handling

Asynchronous event handling using POSIX signals for inter-process communication and system events.

## Signal Basics

### **What are Signals?**
Signals are software interrupts that provide asynchronous communication between processes or from the kernel to a process.

```c
#include <signal.h>
#include <unistd.h>

// Common signals
// SIGINT  - Interrupt (Ctrl+C)
// SIGTERM - Termination request
// SIGKILL - Kill (cannot be caught)
// SIGSTOP - Stop (cannot be caught)
// SIGUSR1 - User-defined signal 1
// SIGUSR2 - User-defined signal 2
// SIGALRM - Alarm clock
// SIGCHLD - Child process terminated
```

### **Signal Handler Function**
```c
#include <stdio.h>
#include <signal.h>

void signal_handler(int sig) {
    switch (sig) {
        case SIGINT:
            printf("\nReceived SIGINT (Ctrl+C)\n");
            break;
        case SIGTERM:
            printf("Received SIGTERM\n");
            break;
        default:
            printf("Received signal %d\n", sig);
    }
}

int main(void) {
    // Register signal handler
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    
    printf("Press Ctrl+C to test signal handling\n");
    while (1) {
        sleep(1);
    }
    
    return 0;
}
```

## Advanced Signal Handling

### **sigaction() - Preferred Method**
```c
#include <signal.h>

void advanced_handler(int sig, siginfo_t *info, void *context) {
    printf("Signal %d from PID %d\n", sig, info->si_pid);
    
    // Access additional signal information
    switch (info->si_code) {
        case SI_USER:
            printf("Sent by kill() or raise()\n");
            break;
        case SI_KERNEL:
            printf("Sent by kernel\n");
            break;
        default:
            printf("Signal code: %d\n", info->si_code);
    }
}

void setup_advanced_handler(void) {
    struct sigaction sa;
    
    sa.sa_sigaction = advanced_handler;
    sa.sa_flags = SA_SIGINFO;  // Use sa_sigaction instead of sa_handler
    sigemptyset(&sa.sa_mask);  // Don't block additional signals
    
    sigaction(SIGUSR1, &sa, NULL);
}
```

### **Signal Masking**
```c
void demonstrate_signal_masking(void) {
    sigset_t mask, old_mask;
    
    // Initialize signal set
    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);
    sigaddset(&mask, SIGTERM);
    
    // Block signals
    sigprocmask(SIG_BLOCK, &mask, &old_mask);
    printf("Signals blocked - Ctrl+C won't work\n");
    sleep(5);
    
    // Restore original mask
    sigprocmask(SIG_SETMASK, &old_mask, NULL);
    printf("Signals unblocked\n");
}
```

## Signal Sets and Manipulation

### **Signal Set Operations**
```c
void signal_set_operations(void) {
    sigset_t set1, set2, result;
    
    // Initialize sets
    sigemptyset(&set1);
    sigfillset(&set2);  // All signals
    
    // Add specific signals
    sigaddset(&set1, SIGINT);
    sigaddset(&set1, SIGTERM);
    sigaddset(&set1, SIGUSR1);
    
    // Remove signal
    sigdelset(&set2, SIGKILL);  // Can't be blocked anyway
    
    // Test membership
    if (sigismember(&set1, SIGINT)) {
        printf("SIGINT is in set1\n");
    }
    
    // Set operations (if available)
    // sigandset(&result, &set1, &set2);  // Intersection
    // sigorset(&result, &set1, &set2);   // Union
}
```

### **Waiting for Signals**
```c
void wait_for_signals(void) {
    sigset_t mask;
    int sig;
    
    // Prepare signal mask
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    sigaddset(&mask, SIGUSR2);
    
    // Block signals so we can wait for them
    sigprocmask(SIG_BLOCK, &mask, NULL);
    
    printf("Waiting for SIGUSR1 or SIGUSR2...\n");
    
    // Wait for signal
    if (sigwait(&mask, &sig) == 0) {
        printf("Received signal %d\n", sig);
    }
}
```

## Real-time Signals

### **Real-time Signal Features**
```c
#include <signal.h>

void realtime_handler(int sig, siginfo_t *info, void *context) {
    printf("Real-time signal %d\n", sig);
    printf("Value: %d\n", info->si_value.sival_int);
    printf("Sender PID: %d\n", info->si_pid);
}

void setup_realtime_signals(void) {
    struct sigaction sa;
    
    sa.sa_sigaction = realtime_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    
    // Real-time signals: SIGRTMIN to SIGRTMAX
    for (int sig = SIGRTMIN; sig <= SIGRTMIN + 5; sig++) {
        sigaction(sig, &sa, NULL);
    }
}

void send_realtime_signal(pid_t pid) {
    union sigval value;
    value.sival_int = 42;
    
    // Send real-time signal with data
    sigqueue(pid, SIGRTMIN, value);
}
```

## Timer-based Signals

### **Alarm Signals**
```c
#include <unistd.h>

volatile sig_atomic_t alarm_fired = 0;

void alarm_handler(int sig) {
    alarm_fired = 1;
    printf("Alarm fired!\n");
}

void timer_example(void) {
    signal(SIGALRM, alarm_handler);
    
    printf("Setting alarm for 3 seconds\n");
    alarm(3);
    
    // Wait for alarm
    while (!alarm_fired) {
        pause();  // Wait for signal
    }
    
    printf("Alarm handled\n");
}
```

### **Interval Timers**
```c
#include <sys/time.h>

void interval_handler(int sig) {
    static int count = 0;
    printf("Timer tick %d\n", ++count);
}

void setup_interval_timer(void) {
    struct itimerval timer;
    
    signal(SIGALRM, interval_handler);
    
    // Set timer: 2 seconds initial, then every 1 second
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;
    
    setitimer(ITIMER_REAL, &timer, NULL);
}
```

## Signal Safety and Async-Signal-Safe Functions

### **Async-Signal-Safe Programming**
```c
#include <signal.h>
#include <unistd.h>

// Global flag for communication with signal handler
volatile sig_atomic_t signal_received = 0;
volatile sig_atomic_t signal_type = 0;

void safe_handler(int sig) {
    // Only async-signal-safe operations allowed here
    signal_received = 1;
    signal_type = sig;
    
    // Safe: write to file descriptor
    const char msg[] = "Signal received\n";
    write(STDERR_FILENO, msg, sizeof(msg) - 1);
    
    // UNSAFE: printf, malloc, most library functions
    // printf("Don't do this in signal handler!\n");
}

void signal_safe_example(void) {
    signal(SIGINT, safe_handler);
    
    while (1) {
        if (signal_received) {
            // Handle signal in main program flow
            printf("Handling signal %d safely\n", signal_type);
            
            if (signal_type == SIGINT) {
                printf("Exiting gracefully\n");
                break;
            }
            
            signal_received = 0;
        }
        
        // Normal program work
        usleep(100000);  // 100ms
    }
}
```

### **Self-Pipe Trick**
```c
int signal_pipe[2];

void pipe_handler(int sig) {
    char byte = sig;
    write(signal_pipe[1], &byte, 1);
}

void setup_signal_pipe(void) {
    pipe(signal_pipe);
    signal(SIGINT, pipe_handler);
    signal(SIGTERM, pipe_handler);
    
    // Make read end non-blocking
    int flags = fcntl(signal_pipe[0], F_GETFL);
    fcntl(signal_pipe[0], F_SETFL, flags | O_NONBLOCK);
}

void handle_signals_via_pipe(void) {
    char sig;
    while (read(signal_pipe[0], &sig, 1) > 0) {
        printf("Received signal %d via pipe\n", sig);
    }
}
```

## Process Control with Signals

### **Child Process Management**
```c
#include <sys/wait.h>

volatile sig_atomic_t child_exited = 0;

void sigchld_handler(int sig) {
    child_exited = 1;
}

void parent_child_example(void) {
    signal(SIGCHLD, sigchld_handler);
    
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child process
        printf("Child process running\n");
        sleep(3);
        printf("Child process exiting\n");
        exit(42);
    } else if (pid > 0) {
        // Parent process
        printf("Parent waiting for child %d\n", pid);
        
        while (!child_exited) {
            printf("Parent doing work...\n");
            sleep(1);
        }
        
        // Reap child
        int status;
        wait(&status);
        printf("Child exited with status %d\n", WEXITSTATUS(status));
    }
}
```

### **Signal-based IPC**
```c
void signal_ipc_example(void) {
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child: wait for parent signal
        sigset_t mask;
        int sig;
        
        sigemptyset(&mask);
        sigaddset(&mask, SIGUSR1);
        sigprocmask(SIG_BLOCK, &mask, NULL);
        
        printf("Child waiting for signal from parent\n");
        sigwait(&mask, &sig);
        printf("Child received signal, continuing\n");
        
        // Send signal back to parent
        kill(getppid(), SIGUSR2);
        exit(0);
    } else if (pid > 0) {
        // Parent: send signal to child
        sleep(2);
        printf("Parent sending signal to child\n");
        kill(pid, SIGUSR1);
        
        // Wait for child response
        sigset_t mask;
        int sig;
        
        sigemptyset(&mask);
        sigaddset(&mask, SIGUSR2);
        sigprocmask(SIG_BLOCK, &mask, NULL);
        
        sigwait(&mask, &sig);
        printf("Parent received response from child\n");
        
        wait(NULL);  // Reap child
    }
}
```

## Error Handling and Debugging

### **Signal Information**
```c
void print_signal_info(int sig, siginfo_t *info, void *context) {
    printf("=== Signal Information ===\n");
    printf("Signal: %d (%s)\n", sig, strsignal(sig));
    printf("Source PID: %d\n", info->si_pid);
    printf("Source UID: %d\n", info->si_uid);
    
    switch (info->si_code) {
        case SI_USER:
            printf("Source: User (kill/raise)\n");
            break;
        case SI_KERNEL:
            printf("Source: Kernel\n");
            break;
        case SI_QUEUE:
            printf("Source: sigqueue()\n");
            printf("Value: %d\n", info->si_value.sival_int);
            break;
        case SI_TIMER:
            printf("Source: Timer\n");
            break;
        default:
            printf("Source code: %d\n", info->si_code);
    }
    
    printf("========================\n");
}
```

### **Signal Debugging**
```c
void debug_signal_mask(void) {
    sigset_t current_mask;
    
    // Get current signal mask
    sigprocmask(SIG_BLOCK, NULL, &current_mask);
    
    printf("Current signal mask:\n");
    for (int sig = 1; sig < NSIG; sig++) {
        if (sigismember(&current_mask, sig)) {
            printf("  Signal %d (%s) is blocked\n", sig, strsignal(sig));
        }
    }
}
```

## Best Practices

### **Graceful Shutdown**
```c
volatile sig_atomic_t shutdown_requested = 0;

void shutdown_handler(int sig) {
    shutdown_requested = 1;
}

void graceful_shutdown_example(void) {
    signal(SIGINT, shutdown_handler);
    signal(SIGTERM, shutdown_handler);
    
    printf("Server starting (Ctrl+C for graceful shutdown)\n");
    
    while (!shutdown_requested) {
        // Simulate server work
        printf("Processing requests...\n");
        sleep(1);
    }
    
    printf("Shutdown requested, cleaning up...\n");
    
    // Cleanup code here
    sleep(2);
    
    printf("Shutdown complete\n");
}
```

### **Signal Handler Best Practices**
```c
// DO: Use sig_atomic_t for shared variables
volatile sig_atomic_t flag = 0;

// DO: Keep handlers simple
void simple_handler(int sig) {
    flag = sig;
}

// DO: Use sigaction() instead of signal()
void setup_robust_handler(void) {
    struct sigaction sa;
    
    sa.sa_handler = simple_handler;
    sa.sa_flags = SA_RESTART;  // Restart interrupted system calls
    sigemptyset(&sa.sa_mask);
    
    sigaction(SIGINT, &sa, NULL);
}

// DON'T: Call non-async-signal-safe functions
void bad_handler(int sig) {
    // These are NOT safe in signal handlers:
    // printf(), malloc(), free(), most library functions
}
```

## Code Example

Run the demo to see signal handling in action:
```bash
make run
```

The demo demonstrates:
- Basic signal registration and handling
- Advanced sigaction() usage
- Signal masking and blocking
- Timer-based signals
- Async-signal-safe programming
- Process communication via signals
- Graceful shutdown patterns
- Signal debugging techniques

**Note**: Some signal operations are Unix/Linux specific and may not work on all platforms.
