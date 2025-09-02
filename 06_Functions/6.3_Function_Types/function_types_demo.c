#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Function prototypes demonstrating different types

// 1. VOID FUNCTIONS (no return value)
void print_header(void);
void print_separator(void);
void display_menu(void);
void initialize_system(void);
void cleanup_resources(void);
void print_welcome_message(const char* name);
void log_message(const char* level, const char* message);

// 2. FUNCTIONS RETURNING BASIC TYPES
int get_random_number(void);
int get_user_choice(void);
double calculate_circle_area(double radius);
char get_grade(int score);
int count_vowels(const char* text);
double convert_celsius_to_fahrenheit(double celsius);

// 3. FUNCTIONS RETURNING STRINGS/POINTERS
char* get_day_name(int day);
const char* get_status_message(int code);
char* format_currency(double amount);
const char* get_file_extension(const char* filename);

// 4. FUNCTIONS WITH NO PARAMETERS
int get_current_year(void);
double get_pi(void);
int get_random_seed(void);
void reset_counter(void);
int get_next_id(void);

// 5. FUNCTIONS WITH MULTIPLE PARAMETERS
int calculate_sum(int a, int b, int c);
double calculate_distance(double x1, double y1, double x2, double y2);
int find_maximum(int arr[], int size);
char* create_full_name(const char* first, const char* last);
int validate_range(int value, int min, int max);

// Global variables for demonstration
static int global_counter = 0;
static int next_id = 1000;

int main() {
    printf("=== Function Types Demo ===\n\n");
    
    // Initialize system
    initialize_system();
    
    // 1. VOID FUNCTIONS DEMONSTRATION
    print_header();
    printf("1. VOID FUNCTIONS (No Return Value)\n");
    print_separator();
    
    print_welcome_message("Alice");
    print_welcome_message("Bob");
    
    log_message("INFO", "System started successfully");
    log_message("WARNING", "Low memory detected");
    log_message("ERROR", "Connection failed");
    
    display_menu();
    printf("\n");
    
    // 2. FUNCTIONS RETURNING BASIC TYPES
    print_header();
    printf("2. FUNCTIONS RETURNING BASIC TYPES\n");
    print_separator();
    
    // Integer return functions
    printf("Random numbers: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", get_random_number());
    }
    printf("\n");
    
    printf("Current year: %d\n", get_current_year());
    printf("Next ID: %d\n", get_next_id());
    printf("Next ID: %d\n", get_next_id());
    
    // Double return functions
    double radius = 5.0;
    printf("Circle area (radius %.1f): %.2f\n", radius, calculate_circle_area(radius));
    printf("Pi constant: %.6f\n", get_pi());
    
    double celsius = 25.0;
    printf("%.1f°C = %.1f°F\n", celsius, convert_celsius_to_fahrenheit(celsius));
    
    // Character return functions
    int scores[] = {95, 87, 76, 64, 45};
    printf("Grade conversion: ");
    for (int i = 0; i < 5; i++) {
        printf("%d→%c ", scores[i], get_grade(scores[i]));
    }
    printf("\n");
    
    // String analysis
    const char* text = "Hello World Programming";
    printf("Vowels in \"%s\": %d\n", text, count_vowels(text));
    printf("\n");
    
    // 3. FUNCTIONS RETURNING STRINGS/POINTERS
    print_header();
    printf("3. FUNCTIONS RETURNING STRINGS/POINTERS\n");
    print_separator();
    
    // Day names
    printf("Days of week: ");
    for (int day = 1; day <= 7; day++) {
        printf("%s ", get_day_name(day));
    }
    printf("\n");
    
    // Status messages
    int status_codes[] = {200, 404, 500, 0};
    for (int i = 0; i < 4; i++) {
        printf("Status %d: %s\n", status_codes[i], get_status_message(status_codes[i]));
    }
    
    // Currency formatting
    double amounts[] = {1234.56, 99.99, 0.75};
    for (int i = 0; i < 3; i++) {
        char* formatted = format_currency(amounts[i]);
        printf("Amount: %s\n", formatted);
        free(formatted);  // Free allocated memory
    }
    
    // File extensions
    const char* files[] = {"document.pdf", "image.jpg", "script.c", "noextension"};
    for (int i = 0; i < 4; i++) {
        printf("File: %s → Extension: %s\n", files[i], get_file_extension(files[i]));
    }
    printf("\n");
    
    // 4. FUNCTIONS WITH NO PARAMETERS
    print_header();
    printf("4. FUNCTIONS WITH NO PARAMETERS\n");
    print_separator();
    
    printf("System constants:\n");
    printf("  Current year: %d\n", get_current_year());
    printf("  Pi value: %.6f\n", get_pi());
    printf("  Random seed: %d\n", get_random_seed());
    
    printf("ID generator:\n");
    for (int i = 0; i < 3; i++) {
        printf("  Generated ID: %d\n", get_next_id());
    }
    
    reset_counter();
    printf("Counter reset completed\n\n");
    
    // 5. FUNCTIONS WITH MULTIPLE PARAMETERS
    print_header();
    printf("5. FUNCTIONS WITH MULTIPLE PARAMETERS\n");
    print_separator();
    
    // Mathematical calculations
    printf("Sum of 10, 20, 30: %d\n", calculate_sum(10, 20, 30));
    
    double distance = calculate_distance(0, 0, 3, 4);
    printf("Distance from (0,0) to (3,4): %.2f\n", distance);
    
    // Array operations
    int numbers[] = {45, 23, 78, 12, 67, 34};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    printf("Maximum in array: %d\n", find_maximum(numbers, size));
    
    // String operations
    char* full_name = create_full_name("John", "Doe");
    printf("Full name: %s\n", full_name);
    free(full_name);
    
    // Validation
    int test_values[] = {15, 105, -5, 50};
    for (int i = 0; i < 4; i++) {
        int value = test_values[i];
        int valid = validate_range(value, 0, 100);
        printf("Value %d in range [0-100]: %s\n", value, valid ? "Valid" : "Invalid");
    }
    printf("\n");
    
    // 6. PRACTICAL EXAMPLE - CALCULATOR SYSTEM
    print_header();
    printf("6. PRACTICAL EXAMPLE - CALCULATOR SYSTEM\n");
    print_separator();
    
    // Simulate calculator operations using different function types
    printf("Calculator Operations:\n");
    
    // No parameter functions for constants
    printf("Using Pi: %.6f\n", get_pi());
    
    // Single parameter functions
    double test_radius = 7.5;
    printf("Circle area (r=%.1f): %.2f\n", test_radius, calculate_circle_area(test_radius));
    
    // Multiple parameter functions
    printf("Sum calculation: %d\n", calculate_sum(25, 35, 40));
    printf("Distance calculation: %.2f\n", calculate_distance(1, 1, 4, 5));
    
    // Void functions for output
    log_message("INFO", "Calculator operations completed");
    
    cleanup_resources();
    printf("\n=== Demo Complete ===\n");
    return 0;
}

// Function implementations

// VOID FUNCTIONS
void print_header(void) {
    printf("----------------------------------------\n");
}

void print_separator(void) {
    printf("........................................\n");
}

void display_menu(void) {
    printf("Menu Options:\n");
    printf("1. Calculate\n");
    printf("2. Settings\n");
    printf("3. Help\n");
    printf("0. Exit\n");
}

void initialize_system(void) {
    srand((unsigned int)time(NULL));  // Initialize random seed
    global_counter = 0;
    printf("System initialized successfully\n\n");
}

void cleanup_resources(void) {
    printf("Cleaning up resources...\n");
    printf("System shutdown complete\n");
}

void print_welcome_message(const char* name) {
    printf("Welcome, %s! Enjoy using our system.\n", name);
}

void log_message(const char* level, const char* message) {
    printf("[%s] %s\n", level, message);
}

// FUNCTIONS RETURNING BASIC TYPES
int get_random_number(void) {
    return rand() % 100 + 1;  // 1-100
}

int get_user_choice(void) {
    // Simulate user input
    return rand() % 4;  // 0-3
}

double calculate_circle_area(double radius) {
    return get_pi() * radius * radius;
}

char get_grade(int score) {
    if (score >= 90) return 'A';
    if (score >= 80) return 'B';
    if (score >= 70) return 'C';
    if (score >= 60) return 'D';
    return 'F';
}

int count_vowels(const char* text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

double convert_celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// FUNCTIONS RETURNING STRINGS/POINTERS
char* get_day_name(int day) {
    static char* days[] = {"", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    if (day >= 1 && day <= 7) {
        return days[day];
    }
    return "Invalid";
}

const char* get_status_message(int code) {
    switch (code) {
        case 200: return "OK";
        case 404: return "Not Found";
        case 500: return "Internal Server Error";
        case 0:   return "No Error";
        default:  return "Unknown Status";
    }
}

char* format_currency(double amount) {
    char* result = malloc(20);
    if (result) {
        sprintf(result, "$%.2f", amount);
    }
    return result;
}

const char* get_file_extension(const char* filename) {
    const char* dot = strrchr(filename, '.');
    if (dot && dot != filename) {
        return dot + 1;
    }
    return "none";
}

// FUNCTIONS WITH NO PARAMETERS
int get_current_year(void) {
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    return tm_info->tm_year + 1900;
}

double get_pi(void) {
    return 3.141592653589793;
}

int get_random_seed(void) {
    return (int)time(NULL);
}

void reset_counter(void) {
    global_counter = 0;
}

int get_next_id(void) {
    return next_id++;
}

// FUNCTIONS WITH MULTIPLE PARAMETERS
int calculate_sum(int a, int b, int c) {
    return a + b + c;
}

double calculate_distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

int find_maximum(int arr[], int size) {
    if (size <= 0) return 0;
    
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

char* create_full_name(const char* first, const char* last) {
    int total_length = strlen(first) + strlen(last) + 2; // +2 for space and null terminator
    char* full_name = malloc(total_length);
    if (full_name) {
        sprintf(full_name, "%s %s", first, last);
    }
    return full_name;
}

int validate_range(int value, int min, int max) {
    return (value >= min && value <= max);
}
