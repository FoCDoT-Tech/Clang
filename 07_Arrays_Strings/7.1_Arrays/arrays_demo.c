#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes for array operations
void print_array(const int arr[], int size);
void print_double_array(const double arr[], int size);
int find_element(const int arr[], int size, int target);
int find_maximum(const int arr[], int size);
int find_minimum(const int arr[], int size);
double calculate_average(const int arr[], int size);
void bubble_sort(int arr[], int size);
void reverse_array(int arr[], int size);
int count_occurrences(const int arr[], int size, int value);
void fill_array_random(int arr[], int size, int max_value);
void copy_array(const int source[], int dest[], int size);

int main() {
    printf("=== Arrays Demo ===\n\n");
    
    // 1. ARRAY DECLARATION AND INITIALIZATION
    printf("1. ARRAY DECLARATION AND INITIALIZATION\n");
    printf("----------------------------------------\n");
    
    // Different initialization methods
    int arr1[5] = {10, 20, 30, 40, 50};           // Full initialization
    int arr2[5] = {1, 2};                         // Partial initialization
    int arr3[] = {100, 200, 300, 400};           // Size determined by elements
    int arr4[6] = {0};                            // All zeros
    
    printf("arr1 (full init): ");
    print_array(arr1, 5);
    
    printf("arr2 (partial init): ");
    print_array(arr2, 5);
    
    printf("arr3 (auto size): ");
    print_array(arr3, 4);
    
    printf("arr4 (all zeros): ");
    print_array(arr4, 6);
    
    // Array size calculation
    printf("\nArray size information:\n");
    printf("arr1 size: %zu bytes, %zu elements\n", 
           sizeof(arr1), sizeof(arr1)/sizeof(arr1[0]));
    printf("arr3 size: %zu bytes, %zu elements\n", 
           sizeof(arr3), sizeof(arr3)/sizeof(arr3[0]));
    printf("\n");
    
    // 2. ARRAY INDEXING AND ACCESS
    printf("2. ARRAY INDEXING AND ACCESS\n");
    printf("----------------------------------------\n");
    
    int numbers[5] = {15, 25, 35, 45, 55};
    printf("Original array: ");
    print_array(numbers, 5);
    
    printf("Individual elements:\n");
    for (int i = 0; i < 5; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }
    
    // Modifying elements
    numbers[0] = 99;
    numbers[4] = 77;
    printf("After modification: ");
    print_array(numbers, 5);
    printf("\n");
    
    // 3. ARRAY OPERATIONS
    printf("3. ARRAY OPERATIONS\n");
    printf("----------------------------------------\n");
    
    int data[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50};
    int data_size = sizeof(data) / sizeof(data[0]);
    
    printf("Original data: ");
    print_array(data, data_size);
    
    // Statistical operations
    printf("Maximum: %d\n", find_maximum(data, data_size));
    printf("Minimum: %d\n", find_minimum(data, data_size));
    printf("Average: %.2f\n", calculate_average(data, data_size));
    
    // Search operations
    int search_values[] = {25, 99, 11};
    for (int i = 0; i < 3; i++) {
        int target = search_values[i];
        int index = find_element(data, data_size, target);
        if (index != -1) {
            printf("Found %d at index %d\n", target, index);
        } else {
            printf("%d not found in array\n", target);
        }
    }
    
    // Count occurrences
    printf("Occurrences of 11: %d\n", count_occurrences(data, data_size, 11));
    printf("\n");
    
    // 4. ARRAY SORTING
    printf("4. ARRAY SORTING\n");
    printf("----------------------------------------\n");
    
    int unsorted[] = {64, 34, 25, 12, 22, 11, 90};
    int sort_size = sizeof(unsorted) / sizeof(unsorted[0]);
    
    printf("Before sorting: ");
    print_array(unsorted, sort_size);
    
    bubble_sort(unsorted, sort_size);
    printf("After sorting: ");
    print_array(unsorted, sort_size);
    printf("\n");
    
    // 5. ARRAY MANIPULATION
    printf("5. ARRAY MANIPULATION\n");
    printf("----------------------------------------\n");
    
    int original[] = {1, 2, 3, 4, 5, 6};
    int manip_size = sizeof(original) / sizeof(original[0]);
    
    printf("Original: ");
    print_array(original, manip_size);
    
    // Reverse array
    reverse_array(original, manip_size);
    printf("Reversed: ");
    print_array(original, manip_size);
    
    // Copy array
    int copied[6];
    copy_array(original, copied, manip_size);
    printf("Copied: ");
    print_array(copied, manip_size);
    printf("\n");
    
    // 6. DIFFERENT DATA TYPES
    printf("6. DIFFERENT DATA TYPES\n");
    printf("----------------------------------------\n");
    
    // Double array
    double temperatures[] = {23.5, 25.0, 22.8, 26.3, 24.1};
    int temp_size = sizeof(temperatures) / sizeof(temperatures[0]);
    printf("Temperatures (°C): ");
    print_double_array(temperatures, temp_size);
    
    // Character array
    char grades[] = {'A', 'B', 'C', 'B', 'A', 'C', 'B'};
    int grade_size = sizeof(grades) / sizeof(grades[0]);
    printf("Grades: ");
    for (int i = 0; i < grade_size; i++) {
        printf("%c ", grades[i]);
    }
    printf("\n");
    
    // Boolean-like array
    int flags[] = {1, 0, 1, 1, 0, 0, 1};
    int flag_size = sizeof(flags) / sizeof(flags[0]);
    printf("Flags: ");
    for (int i = 0; i < flag_size; i++) {
        printf("%s ", flags[i] ? "true" : "false");
    }
    printf("\n\n");
    
    // 7. DYNAMIC ARRAY OPERATIONS
    printf("7. DYNAMIC ARRAY OPERATIONS\n");
    printf("----------------------------------------\n");
    
    // Fill array with random numbers
    srand((unsigned int)time(NULL));
    int random_array[8];
    int random_size = sizeof(random_array) / sizeof(random_array[0]);
    
    fill_array_random(random_array, random_size, 100);
    printf("Random array: ");
    print_array(random_array, random_size);
    
    // Find statistics
    printf("Statistics:\n");
    printf("  Max: %d\n", find_maximum(random_array, random_size));
    printf("  Min: %d\n", find_minimum(random_array, random_size));
    printf("  Avg: %.2f\n", calculate_average(random_array, random_size));
    printf("\n");
    
    // 8. PRACTICAL EXAMPLE - STUDENT SCORES
    printf("8. PRACTICAL EXAMPLE - STUDENT SCORES\n");
    printf("----------------------------------------\n");
    
    int scores[] = {85, 92, 78, 96, 88, 74, 91, 83, 79, 94};
    int num_students = sizeof(scores) / sizeof(scores[0]);
    
    printf("Student scores: ");
    print_array(scores, num_students);
    
    printf("Class statistics:\n");
    printf("  Highest score: %d\n", find_maximum(scores, num_students));
    printf("  Lowest score: %d\n", find_minimum(scores, num_students));
    printf("  Class average: %.2f\n", calculate_average(scores, num_students));
    
    // Grade distribution
    int grade_counts[5] = {0}; // A, B, C, D, F
    for (int i = 0; i < num_students; i++) {
        if (scores[i] >= 90) grade_counts[0]++;      // A
        else if (scores[i] >= 80) grade_counts[1]++; // B
        else if (scores[i] >= 70) grade_counts[2]++; // C
        else if (scores[i] >= 60) grade_counts[3]++; // D
        else grade_counts[4]++;                      // F
    }
    
    printf("Grade distribution:\n");
    char grade_letters[] = {'A', 'B', 'C', 'D', 'F'};
    for (int i = 0; i < 5; i++) {
        printf("  %c: %d students\n", grade_letters[i], grade_counts[i]);
    }
    
    // Sort scores for ranking
    int sorted_scores[10];
    copy_array(scores, sorted_scores, num_students);
    bubble_sort(sorted_scores, num_students);
    printf("Sorted scores (ascending): ");
    print_array(sorted_scores, num_students);
    
    printf("\n=== Demo Complete ===\n");
    return 0;
}

// Function implementations

void print_array(const int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

void print_double_array(const double arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%.1f", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int find_element(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}

int find_maximum(const int arr[], int size) {
    if (size <= 0) return 0;
    
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int find_minimum(const int arr[], int size) {
    if (size <= 0) return 0;
    
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

double calculate_average(const int arr[], int size) {
    if (size <= 0) return 0.0;
    
    long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void reverse_array(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int count_occurrences(const int arr[], int size, int value) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            count++;
        }
    }
    return count;
}

void fill_array_random(int arr[], int size, int max_value) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % max_value + 1;  // 1 to max_value
    }
}

void copy_array(const int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}
