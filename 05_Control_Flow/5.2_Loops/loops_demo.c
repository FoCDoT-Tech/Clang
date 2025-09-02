#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void demonstrate_for_loop(void);
void demonstrate_while_loop(void);
void demonstrate_do_while_loop(void);
void demonstrate_nested_loops(void);
void demonstrate_practical_examples(void);
void demonstrate_loop_patterns(void);
void print_multiplication_table(int number);
int find_in_array(int arr[], int size, int target);

int main() {
    printf("=== Loops Demo ===\n\n");
    
    demonstrate_for_loop();
    demonstrate_while_loop();
    demonstrate_do_while_loop();
    demonstrate_nested_loops();
    demonstrate_practical_examples();
    demonstrate_loop_patterns();
    
    printf("✓ All loop types demonstrated!\n");
    return 0;
}

void demonstrate_for_loop(void) {
    printf("1. FOR LOOP:\n");
    
    // Basic counting
    printf("Counting from 1 to 5: ");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    // Counting backwards
    printf("Countdown from 5 to 1: ");
    for (int i = 5; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");
    
    // Step by 2
    printf("Even numbers 0 to 10: ");
    for (int i = 0; i <= 10; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    
    // Array processing
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // Sum calculation
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    printf("Sum of array: %d\n", sum);
    
    // Multiple variables in for loop
    printf("Multiple variables: ");
    for (int i = 0, j = 10; i < 5; i++, j--) {
        printf("(%d,%d) ", i, j);
    }
    printf("\n\n");
}

void demonstrate_while_loop(void) {
    printf("2. WHILE LOOP:\n");
    
    // Basic counting
    printf("Counting with while: ");
    int count = 1;
    while (count <= 5) {
        printf("%d ", count);
        count++;
    }
    printf("\n");
    
    // Input validation simulation
    int attempts = 0;
    int max_attempts = 3;
    int correct_password = 1234;
    int user_input = 1111;  // Simulated wrong input
    
    printf("Password attempts:\n");
    while (attempts < max_attempts && user_input != correct_password) {
        attempts++;
        printf("Attempt %d: Password %d ", attempts, user_input);
        
        if (user_input == correct_password) {
            printf("✓ Correct!\n");
        } else {
            printf("✗ Wrong\n");
            user_input = (attempts == 2) ? 1234 : 9999;  // Correct on 3rd attempt
        }
    }
    
    if (user_input == correct_password) {
        printf("✓ Access granted after %d attempts\n", attempts);
    } else {
        printf("✗ Access denied - too many attempts\n");
    }
    
    // Finding first power of 2 greater than 100
    int power = 1;
    int exponent = 0;
    while (power <= 100) {
        power *= 2;
        exponent++;
    }
    printf("First power of 2 > 100: 2^%d = %d\n", exponent, power);
    
    printf("\n");
}

void demonstrate_do_while_loop(void) {
    printf("3. DO-WHILE LOOP:\n");
    
    // Menu system simulation
    int choice = 0;
    printf("Menu system simulation:\n");
    
    do {
        printf("--- Menu ---\n");
        printf("1. View Profile\n");
        printf("2. Edit Settings\n");
        printf("3. Help\n");
        printf("0. Exit\n");
        
        // Simulate user choices
        static int menu_choices[] = {1, 2, 3, 0};
        static int choice_index = 0;
        choice = menu_choices[choice_index++];
        
        printf("Choice: %d\n", choice);
        
        switch (choice) {
            case 1:
                printf("→ Displaying profile...\n");
                break;
            case 2:
                printf("→ Opening settings...\n");
                break;
            case 3:
                printf("→ Showing help...\n");
                break;
            case 0:
                printf("→ Goodbye!\n");
                break;
            default:
                printf("→ Invalid choice\n");
        }
        printf("\n");
        
    } while (choice != 0);
    
    // Number guessing game simulation
    srand(time(NULL));
    int secret = rand() % 10 + 1;  // Random number 1-10
    int guess;
    int guesses = 0;
    
    printf("Number guessing game (1-10):\n");
    printf("Secret number: %d (for demo)\n", secret);
    
    do {
        guesses++;
        // Simulate guesses
        if (guesses == 1) guess = 5;
        else if (guesses == 2) guess = secret > 5 ? 8 : 3;
        else guess = secret;
        
        printf("Guess %d: %d ", guesses, guess);
        
        if (guess == secret) {
            printf("✓ Correct!\n");
        } else if (guess < secret) {
            printf("Too low\n");
        } else {
            printf("Too high\n");
        }
        
    } while (guess != secret && guesses < 5);
    
    printf("Game ended in %d guesses\n\n", guesses);
}

void demonstrate_nested_loops(void) {
    printf("4. NESTED LOOPS:\n");
    
    // Multiplication table
    printf("Multiplication table (1-5):\n");
    printf("   ");
    for (int i = 1; i <= 5; i++) {
        printf("%4d", i);
    }
    printf("\n");
    
    for (int i = 1; i <= 5; i++) {
        printf("%2d:", i);
        for (int j = 1; j <= 5; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
    
    // Pattern printing
    printf("\nNumber patterns:\n");
    
    // Right triangle
    printf("Right triangle:\n");
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    
    // Star pyramid
    printf("\nStar pyramid:\n");
    for (int i = 1; i <= 5; i++) {
        // Print spaces
        for (int j = 1; j <= 5 - i; j++) {
            printf(" ");
        }
        // Print stars
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    // Matrix processing
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    printf("\nMatrix operations:\n");
    printf("Original matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Calculate row sums
    printf("Row sums: ");
    for (int i = 0; i < 3; i++) {
        int row_sum = 0;
        for (int j = 0; j < 3; j++) {
            row_sum += matrix[i][j];
        }
        printf("%d ", row_sum);
    }
    printf("\n\n");
}

void demonstrate_practical_examples(void) {
    printf("5. PRACTICAL EXAMPLES:\n");
    
    // Factorial calculation
    int n = 5;
    long factorial = 1;
    printf("Calculating %d! = ", n);
    
    for (int i = 1; i <= n; i++) {
        factorial *= i;
        if (i == 1) {
            printf("%d", i);
        } else {
            printf(" × %d", i);
        }
    }
    printf(" = %ld\n", factorial);
    
    // Prime number check
    int number = 17;
    int is_prime = 1;
    
    if (number <= 1) {
        is_prime = 0;
    } else {
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                is_prime = 0;
                break;
            }
        }
    }
    
    printf("%d is %s\n", number, is_prime ? "prime" : "not prime");
    
    // Fibonacci sequence
    printf("Fibonacci sequence (first 10): ");
    int fib1 = 0, fib2 = 1;
    printf("%d %d ", fib1, fib2);
    
    for (int i = 2; i < 10; i++) {
        int next = fib1 + fib2;
        printf("%d ", next);
        fib1 = fib2;
        fib2 = next;
    }
    printf("\n");
    
    // Array search
    int search_array[] = {10, 25, 30, 45, 50, 65, 70};
    int array_size = sizeof(search_array) / sizeof(search_array[0]);
    int target = 45;
    
    int found_index = find_in_array(search_array, array_size, target);
    if (found_index != -1) {
        printf("Found %d at index %d\n", target, found_index);
    } else {
        printf("%d not found in array\n", target);
    }
    
    // Multiplication table function
    print_multiplication_table(7);
    
    printf("\n");
}

void demonstrate_loop_patterns(void) {
    printf("6. COMMON LOOP PATTERNS:\n");
    
    // Accumulation pattern
    int values[] = {5, 10, 15, 20, 25};
    int size = sizeof(values) / sizeof(values[0]);
    
    int sum = 0;
    int product = 1;
    int max = values[0];
    int min = values[0];
    
    for (int i = 0; i < size; i++) {
        sum += values[i];           // Sum accumulation
        product *= values[i];       // Product accumulation
        if (values[i] > max) max = values[i];  // Maximum finding
        if (values[i] < min) min = values[i];  // Minimum finding
    }
    
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
    printf("Sum: %d, Product: %d, Max: %d, Min: %d\n", sum, product, max, min);
    
    // Counting pattern
    char text[] = "Hello World!";
    int vowels = 0, consonants = 0, spaces = 0, others = 0;
    
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vowels++;
        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            consonants++;
        } else if (c == ' ') {
            spaces++;
        } else {
            others++;
        }
    }
    
    printf("Text analysis of \"%s\":\n", text);
    printf("Vowels: %d, Consonants: %d, Spaces: %d, Others: %d\n", 
           vowels, consonants, spaces, others);
    
    // Validation pattern
    printf("Input validation simulation:\n");
    int valid_input = 0;
    int input_attempts = 0;
    int simulated_inputs[] = {-5, 150, 75};  // Invalid, invalid, valid
    
    while (!valid_input && input_attempts < 3) {
        int input = simulated_inputs[input_attempts];
        input_attempts++;
        
        printf("Attempt %d: Input = %d ", input_attempts, input);
        
        if (input >= 0 && input <= 100) {
            printf("✓ Valid\n");
            valid_input = 1;
        } else {
            printf("✗ Invalid (must be 0-100)\n");
        }
    }
    
    if (valid_input) {
        printf("✓ Input accepted\n");
    } else {
        printf("✗ Too many invalid attempts\n");
    }
    
    printf("\n");
}

void print_multiplication_table(int number) {
    printf("Multiplication table for %d:\n", number);
    for (int i = 1; i <= 10; i++) {
        printf("%d × %d = %d\n", number, i, number * i);
    }
}

int find_in_array(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}
