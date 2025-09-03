#include <stdio.h>
#include <stdlib.h>
#include "math_utils.h"
#include "string_utils.h"
#include "vector.h"
#include "logger.h"

int main(void) {
    printf("=== Multi-file Program Demo ===\n\n");
    
    // Initialize logger
    logger_init("demo.log");
    LOG_INFO("Multi-file program demo started");
    
    // Math utilities demonstration
    printf("1. MATH UTILITIES\n");
    printf("----------------------------------------\n");
    
    double radius = 5.0;
    double area = calculate_area(radius);
    printf("Area of circle with radius %.1f: %.2f\n", radius, area);
    LOG_DEBUG("Calculated area: %.2f", area);
    
    double volume = calculate_volume(radius, 10.0);
    printf("Volume of cylinder (r=%.1f, h=%.1f): %.2f\n", radius, 10.0, volume);
    
    int fact = factorial(5);
    printf("Factorial of 5: %d\n", fact);
    
    Point2D p1 = {3.0, 4.0};
    Point2D p2 = {0.0, 0.0};
    double dist = distance_2d(&p1, &p2);
    printf("Distance between (%.1f,%.1f) and (%.1f,%.1f): %.2f\n", 
           p1.x, p1.y, p2.x, p2.y, dist);
    
    printf("\n");
    
    // String utilities demonstration
    printf("2. STRING UTILITIES\n");
    printf("----------------------------------------\n");
    
    StrUtils_String* str = strutils_create("Hello");
    if (str) {
        printf("Created string: '%s'\n", strutils_to_cstring(str));
        
        strutils_append(str, " World");
        printf("After append: '%s'\n", strutils_to_cstring(str));
        
        strutils_prepend(str, ">>> ");
        printf("After prepend: '%s'\n", strutils_to_cstring(str));
        
        printf("String length: %zu\n", strutils_length(str));
        
        strutils_destroy(str);
        LOG_INFO("String operations completed");
    }
    
    printf("\n");
    
    // Vector demonstration
    printf("3. DYNAMIC VECTOR\n");
    printf("----------------------------------------\n");
    
    Vector* vec = vector_create(2);
    if (vec) {
        printf("Created vector with capacity %zu\n", vector_capacity(vec));
        
        // Add elements
        for (int i = 1; i <= 10; i++) {
            vector_push(vec, i * 10);
        }
        
        printf("Vector size after adding 10 elements: %zu\n", vector_size(vec));
        printf("Vector capacity: %zu\n", vector_capacity(vec));
        
        printf("Vector contents: ");
        for (size_t i = 0; i < vector_size(vec); i++) {
            printf("%d ", vector_get(vec, i));
        }
        printf("\n");
        
        // Modify element
        vector_set(vec, 5, 999);
        printf("After setting index 5 to 999: ");
        for (size_t i = 0; i < vector_size(vec); i++) {
            printf("%d ", vector_get(vec, i));
        }
        printf("\n");
        
        // Pop elements
        printf("Popping elements: ");
        while (vector_size(vec) > 5) {
            printf("%d ", vector_pop(vec));
        }
        printf("\n");
        
        printf("Final vector size: %zu\n", vector_size(vec));
        
        vector_destroy(vec);
        LOG_INFO("Vector operations completed");
    }
    
    printf("\n");
    
    // Demonstrate module interaction
    printf("4. MODULE INTERACTION\n");
    printf("----------------------------------------\n");
    
    Vector* math_results = vector_create(5);
    if (math_results) {
        // Store math results in vector
        vector_push(math_results, (int)area);
        vector_push(math_results, (int)volume);
        vector_push(math_results, fact);
        vector_push(math_results, (int)dist);
        
        printf("Math results stored in vector:\n");
        for (size_t i = 0; i < vector_size(math_results); i++) {
            printf("  Result %zu: %d\n", i, vector_get(math_results, i));
        }
        
        // Create string representation
        StrUtils_String* result_str = strutils_create("Results: ");
        if (result_str) {
            for (size_t i = 0; i < vector_size(math_results); i++) {
                char buffer[32];
                snprintf(buffer, sizeof(buffer), "%d", vector_get(math_results, i));
                strutils_append(result_str, buffer);
                if (i < vector_size(math_results) - 1) {
                    strutils_append(result_str, ", ");
                }
            }
            
            printf("String representation: '%s'\n", strutils_to_cstring(result_str));
            LOG_INFO("Combined results: %s", strutils_to_cstring(result_str));
            
            strutils_destroy(result_str);
        }
        
        vector_destroy(math_results);
    }
    
    printf("\n");
    
    // Performance demonstration
    printf("5. PERFORMANCE TEST\n");
    printf("----------------------------------------\n");
    
    printf("Creating large vector and performing operations...\n");
    Vector* large_vec = vector_create(1000);
    if (large_vec) {
        // Add many elements
        for (int i = 0; i < 10000; i++) {
            vector_push(large_vec, i);
        }
        
        printf("Added 10,000 elements\n");
        printf("Final capacity: %zu\n", vector_capacity(large_vec));
        
        // Calculate sum using vector
        long sum = 0;
        for (size_t i = 0; i < vector_size(large_vec); i++) {
            sum += vector_get(large_vec, i);
        }
        
        printf("Sum of all elements: %ld\n", sum);
        LOG_INFO("Performance test completed with sum: %ld", sum);
        
        vector_destroy(large_vec);
    }
    
    printf("\n");
    
    LOG_INFO("Multi-file program demo completed successfully");
    logger_cleanup();
    
    printf("=== Demo Complete ===\n");
    printf("Check 'demo.log' for logged messages\n");
    
    return 0;
}
