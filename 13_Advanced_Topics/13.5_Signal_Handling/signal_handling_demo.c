#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <errno.h>
#include <fcntl.h>

// Function prototypes
void demonstrate_basic_signals(void);
void demonstrate_advanced_signals(void);
void demonstrate_signal_masking(void);
void demonstrate_timer_signals(void);
void demonstrate_signal_safety(void);
void demonstrate_process_signals(void);
void demonstrate_graceful_shutdown(void);

// Global variables for signal communication
volatile sig_atomic_t signal_received = 0;
volatile sig_atomic_t signal_type = 0;
volatile sig_atomic_t alarm_fired = 0;
volatile sig_atomic_t child_exited = 0;
volatile sig_atomic_t shutdown_requested = 0;
volatile sig_atomic_t timer_count = 0;

// Signal pipe for self-pipe trick
int signal_pipe[2] = {-1, -1};

// Basic signal handler
void basic_handler(int sig) {
    const char* signal_name;
    
    switch (sig) {
        case SIGINT:
            signal_name = "SIGINT (Ctrl+C)";
            break;
        case SIGTERM:
            signal_name = "SIGTERM";
            break;
        case SIGUSR1:
            signal_name = "SIGUSR1";
            break;
        case SIGUSR2:
            signal_name = "SIGUSR2";
            break;
        default:
            signal_name = "Unknown";
    }
    
    // Use write() which is async-signal-safe
    char buffer[128];
    int len = snprintf(buffer, sizeof(buffer), "\n[HANDLER] Received %s\n", signal_name);
    if (len > 0 && len < (int)sizeof(buffer)) {
        write(STDERR_FILENO, buffer, len);
    }
    
    signal_received = 1;
    signal_type = sig;
}

// Advanced signal handler with siginfo
void advanced_handler(int sig, siginfo_t *info, void *context) {
    (void)context; // Unused parameter
    
    char buffer[256];
    int len = snprintf(buffer, sizeof(buffer), 
                      "\n[ADVANCED] Signal %d from PID %d, code %d\n", 
                      sig, info->si_pid, info->si_code);
    
    if (len > 0 && len < (int)sizeof(buffer)) {
        write(STDERR_FILENO, buffer, len);
    }
    
    signal_received = 1;
    signal_type = sig;
}

// Alarm handler
void alarm_handler(int sig) {
    (void)sig; // Unused parameter
    const char msg[] = "\n[ALARM] Timer expired!\n";
    write(STDERR_FILENO, msg, sizeof(msg) - 1);
    alarm_fired = 1;
}

// Interval timer handler
void interval_handler(int sig) {
    (void)sig; // Unused parameter
    timer_count++;
    
    char buffer[64];
    int len = snprintf(buffer, sizeof(buffer), "\n[TIMER] Tick %d\n", (int)timer_count);
    if (len > 0 && len < (int)sizeof(buffer)) {
        write(STDERR_FILENO, buffer, len);
    }
}

// Child process handler
void sigchld_handler(int sig) {
    (void)sig; // Unused parameter
    const char msg[] = "\n[CHILD] Child process exited\n";
    write(STDERR_FILENO, msg, sizeof(msg) - 1);
    child_exited = 1;
}

// Shutdown handler
void shutdown_handler(int sig) {
    (void)sig; // Unused parameter
    const char msg[] = "\n[SHUTDOWN] Graceful shutdown requested\n";
    write(STDERR_FILENO, msg, sizeof(msg) - 1);
    shutdown_requested = 1;
}

// Pipe handler for self-pipe trick
void pipe_handler(int sig) {
    char byte = (char)sig;
    if (signal_pipe[1] != -1) {
        write(signal_pipe[1], &byte, 1);
    }
}

// Helper function to setup sigaction
int setup_sigaction(int sig, void (*handler)(int, siginfo_t*, void*)) {
    struct sigaction sa;
    
    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO | SA_RESTART;
    sigemptyset(&sa.sa_mask);
    
    return sigaction(sig, &sa, NULL);
}

// Helper function to setup basic signal
int setup_signal(int sig, void (*handler)(int)) {
    struct sigaction sa;
    
    sa.sa_handler = handler;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);
    
    return sigaction(sig, &sa, NULL);
}

int main(void) {
    printf("=== Signal Handling Demo ===\n\n");
    printf("Note: This demo shows signal handling concepts.\n");
    printf("Some features may be platform-specific (Unix/Linux).\n\n");
    
    demonstrate_basic_signals();
    demonstrate_advanced_signals();
    demonstrate_signal_masking();
    demonstrate_timer_signals();
    demonstrate_signal_safety();
    demonstrate_process_signals();
    demonstrate_graceful_shutdown();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_basic_signals(void) {
    printf("1. BASIC SIGNAL HANDLING\n");
    printf("----------------------------------------\n");
    
    // Setup basic signal handlers
    if (setup_signal(SIGUSR1, basic_handler) != 0) {
        perror("Failed to setup SIGUSR1 handler");
        return;
    }
    
    if (setup_signal(SIGUSR2, basic_handler) != 0) {
        perror("Failed to setup SIGUSR2 handler");
        return;
    }
    
    printf("Sending SIGUSR1 to self...\n");
    kill(getpid(), SIGUSR1);
    
    // Give handler time to execute
    usleep(100000);
    
    if (signal_received && signal_type == SIGUSR1) {
        printf("Successfully handled SIGUSR1\n");
    }
    
    // Reset flags
    signal_received = 0;
    signal_type = 0;
    
    printf("Sending SIGUSR2 to self...\n");
    kill(getpid(), SIGUSR2);
    
    usleep(100000);
    
    if (signal_received && signal_type == SIGUSR2) {
        printf("Successfully handled SIGUSR2\n");
    }
    
    printf("Basic signal handling demonstrated\n\n");
}

void demonstrate_advanced_signals(void) {
    printf("2. ADVANCED SIGNAL HANDLING (sigaction)\n");
    printf("----------------------------------------\n");
    
    // Setup advanced signal handler
    if (setup_sigaction(SIGUSR1, advanced_handler) != 0) {
        perror("Failed to setup advanced SIGUSR1 handler");
        return;
    }
    
    // Reset flags
    signal_received = 0;
    signal_type = 0;
    
    printf("Sending SIGUSR1 with sigaction handler...\n");
    kill(getpid(), SIGUSR1);
    
    usleep(100000);
    
    if (signal_received && signal_type == SIGUSR1) {
        printf("Advanced signal handler executed successfully\n");
    }
    
    printf("Advanced signal handling demonstrated\n\n");
}

void demonstrate_signal_masking(void) {
    printf("3. SIGNAL MASKING AND BLOCKING\n");
    printf("----------------------------------------\n");
    
    sigset_t mask, old_mask;
    
    // Initialize signal set
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    
    printf("Blocking SIGUSR1...\n");
    if (sigprocmask(SIG_BLOCK, &mask, &old_mask) != 0) {
        perror("Failed to block signal");
        return;
    }
    
    // Reset flags
    signal_received = 0;
    signal_type = 0;
    
    printf("Sending SIGUSR1 while blocked...\n");
    kill(getpid(), SIGUSR1);
    
    usleep(100000);
    
    if (!signal_received) {
        printf("Signal was successfully blocked\n");
    }
    
    printf("Unblocking SIGUSR1...\n");
    if (sigprocmask(SIG_SETMASK, &old_mask, NULL) != 0) {
        perror("Failed to unblock signal");
        return;
    }
    
    // Give time for pending signal to be delivered
    usleep(100000);
    
    if (signal_received && signal_type == SIGUSR1) {
        printf("Pending signal was delivered after unblocking\n");
    }
    
    printf("Signal masking demonstrated\n\n");
}

void demonstrate_timer_signals(void) {
    printf("4. TIMER-BASED SIGNALS\n");
    printf("----------------------------------------\n");
    
    // Setup alarm handler
    if (setup_signal(SIGALRM, alarm_handler) != 0) {
        perror("Failed to setup alarm handler");
        return;
    }
    
    // Reset flag
    alarm_fired = 0;
    
    printf("Setting alarm for 2 seconds...\n");
    alarm(2);
    
    // Wait for alarm
    int wait_count = 0;
    while (!alarm_fired && wait_count < 30) {  // Max 3 seconds
        printf("Waiting... (%d)\n", wait_count + 1);
        usleep(100000);  // 100ms
        wait_count++;
    }
    
    if (alarm_fired) {
        printf("Alarm signal handled successfully\n");
    } else {
        printf("Alarm did not fire within expected time\n");
    }
    
    // Demonstrate interval timer
    printf("\nSetting up interval timer (3 ticks)...\n");
    if (setup_signal(SIGALRM, interval_handler) != 0) {
        perror("Failed to setup interval handler");
        return;
    }
    
    struct itimerval timer;
    timer_count = 0;
    
    // Set timer: 1 second initial, then every 500ms
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 500000;  // 500ms
    
    if (setitimer(ITIMER_REAL, &timer, NULL) != 0) {
        perror("Failed to set interval timer");
        return;
    }
    
    // Wait for a few ticks
    wait_count = 0;
    while (timer_count < 3 && wait_count < 50) {  // Max 5 seconds
        usleep(100000);  // 100ms
        wait_count++;
    }
    
    // Stop timer
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);
    
    printf("Interval timer demonstrated (%d ticks)\n\n", (int)timer_count);
}

void demonstrate_signal_safety(void) {
    printf("5. SIGNAL SAFETY AND SELF-PIPE TRICK\n");
    printf("----------------------------------------\n");
    
    // Create pipe for self-pipe trick
    if (pipe(signal_pipe) != 0) {
        perror("Failed to create signal pipe");
        return;
    }
    
    // Make read end non-blocking
    int flags = fcntl(signal_pipe[0], F_GETFL);
    if (flags != -1) {
        fcntl(signal_pipe[0], F_SETFL, flags | O_NONBLOCK);
    }
    
    // Setup pipe handler
    if (setup_signal(SIGUSR1, pipe_handler) != 0) {
        perror("Failed to setup pipe handler");
        close(signal_pipe[0]);
        close(signal_pipe[1]);
        return;
    }
    
    printf("Using self-pipe trick for signal safety...\n");
    
    // Send signal
    kill(getpid(), SIGUSR1);
    
    // Check pipe for signal
    usleep(100000);  // Give handler time to write
    
    char sig_byte;
    ssize_t bytes_read = read(signal_pipe[0], &sig_byte, 1);
    
    if (bytes_read > 0) {
        printf("Received signal %d via self-pipe trick\n", (int)sig_byte);
        printf("This method allows safe signal handling in main loop\n");
    } else {
        printf("No signal received via pipe\n");
    }
    
    // Cleanup
    close(signal_pipe[0]);
    close(signal_pipe[1]);
    signal_pipe[0] = signal_pipe[1] = -1;
    
    printf("Signal safety demonstrated\n\n");
}

void demonstrate_process_signals(void) {
    printf("6. PROCESS COMMUNICATION WITH SIGNALS\n");
    printf("----------------------------------------\n");
    
    // Setup child handler
    if (setup_signal(SIGCHLD, sigchld_handler) != 0) {
        perror("Failed to setup SIGCHLD handler");
        return;
    }
    
    child_exited = 0;
    
    printf("Creating child process...\n");
    pid_t pid = fork();
    
    if (pid == 0) {
        // Child process
        printf("Child process (PID %d) running...\n", getpid());
        sleep(2);
        printf("Child process exiting...\n");
        exit(42);
    } else if (pid > 0) {
        // Parent process
        printf("Parent waiting for child (PID %d)...\n", pid);
        
        int wait_count = 0;
        while (!child_exited && wait_count < 50) {  // Max 5 seconds
            usleep(100000);  // 100ms
            wait_count++;
        }
        
        if (child_exited) {
            // Reap child
            int status;
            if (waitpid(pid, &status, WNOHANG) > 0) {
                if (WIFEXITED(status)) {
                    printf("Child exited with status %d\n", WEXITSTATUS(status));
                }
            }
        } else {
            printf("Child did not exit within expected time\n");
            // Kill child if still running
            kill(pid, SIGTERM);
            waitpid(pid, NULL, 0);
        }
    } else {
        perror("Failed to fork");
        return;
    }
    
    printf("Process signal communication demonstrated\n\n");
}

void demonstrate_graceful_shutdown(void) {
    printf("7. GRACEFUL SHUTDOWN PATTERN\n");
    printf("----------------------------------------\n");
    
    // Setup shutdown handlers
    if (setup_signal(SIGTERM, shutdown_handler) != 0) {
        perror("Failed to setup SIGTERM handler");
        return;
    }
    
    shutdown_requested = 0;
    
    printf("Simulating server with graceful shutdown...\n");
    printf("Sending SIGTERM to trigger shutdown...\n");
    
    // Simulate server startup
    usleep(100000);
    
    // Send shutdown signal
    kill(getpid(), SIGTERM);
    
    // Give handler time to execute
    usleep(100000);
    
    if (shutdown_requested) {
        printf("Shutdown signal received, cleaning up...\n");
        
        // Simulate cleanup work
        for (int i = 0; i < 3; i++) {
            printf("Cleanup step %d...\n", i + 1);
            usleep(200000);  // 200ms
        }
        
        printf("Graceful shutdown complete\n");
    } else {
        printf("Shutdown signal not received\n");
    }
    
    printf("Graceful shutdown pattern demonstrated\n\n");
}
