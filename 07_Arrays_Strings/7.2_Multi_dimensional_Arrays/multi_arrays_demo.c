#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for array dimensions
#define ROWS 3
#define COLS 4
#define BOARD_SIZE 8
#define DEPTH 2

// Function prototypes for matrix operations
void print_matrix(int matrix[][COLS], int rows);
void print_square_matrix(int matrix[][3], int size);
void print_char_matrix(char matrix[][BOARD_SIZE], int rows);
void initialize_matrix(int matrix[][COLS], int rows, int value);
void fill_matrix_sequential(int matrix[][COLS], int rows);
void transpose_matrix(int source[][3], int dest[][3], int size);
void add_matrices(int a[][3], int b[][3], int result[][3], int size);
void multiply_matrices(int a[][3], int b[][3], int result[][3], int size);
int find_in_matrix(int matrix[][COLS], int rows, int target);
void print_3d_array(int arr[][ROWS][COLS], int depth);

int main() {
    printf("=== Multi-dimensional Arrays Demo ===\n\n");
    
    // 1. 2D ARRAY DECLARATION AND INITIALIZATION
    printf("1. 2D ARRAY DECLARATION AND INITIALIZATION\n");
    printf("----------------------------------------\n");
    
    // Different initialization methods
    int matrix1[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    int matrix2[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    
    int matrix3[3][4] = {
        {10, 20},
        {30, 40, 50},
        {60}
    };
    
    printf("Matrix1 (row-by-row init):\n");
    print_matrix(matrix1, 3);
    
    printf("Matrix2 (linear init):\n");
    print_matrix(matrix2, 3);
    
    printf("Matrix3 (partial init):\n");
    print_matrix(matrix3, 3);
    
    // Array size information
    printf("Matrix size: %zu bytes\n", sizeof(matrix1));
    printf("Total elements: %zu\n", sizeof(matrix1) / sizeof(matrix1[0][0]));
    printf("\n");
    
    // 2. MATRIX TRAVERSAL AND ACCESS
    printf("2. MATRIX TRAVERSAL AND ACCESS\n");
    printf("----------------------------------------\n");
    
    int data[3][4];
    fill_matrix_sequential(data, 3);
    
    printf("Sequential filled matrix:\n");
    print_matrix(data, 3);
    
    printf("Element access:\n");
    printf("data[0][0] = %d\n", data[0][0]);
    printf("data[1][2] = %d\n", data[1][2]);
    printf("data[2][3] = %d\n", data[2][3]);
    
    // Modify elements
    data[1][1] = 99;
    data[2][0] = 88;
    printf("After modification:\n");
    print_matrix(data, 3);
    printf("\n");
    
    // 3. MATRIX OPERATIONS
    printf("3. MATRIX OPERATIONS\n");
    printf("----------------------------------------\n");
    
    // Square matrices for operations
    int matA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int matB[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    
    printf("Matrix A:\n");
    print_square_matrix(matA, 3);
    
    printf("Matrix B:\n");
    print_square_matrix(matB, 3);
    
    // Matrix addition
    int sum[3][3];
    add_matrices(matA, matB, sum, 3);
    printf("A + B:\n");
    print_square_matrix(sum, 3);
    
    // Matrix transpose
    int transpose[3][3];
    transpose_matrix(matA, transpose, 3);
    printf("Transpose of A:\n");
    print_square_matrix(transpose, 3);
    
    // Matrix multiplication (simplified)
    int product[3][3];
    multiply_matrices(matA, matB, product, 3);
    printf("A × B:\n");
    print_square_matrix(product, 3);
    printf("\n");
    
    // 4. SEARCH IN 2D ARRAY
    printf("4. SEARCH IN 2D ARRAY\n");
    printf("----------------------------------------\n");
    
    int search_matrix[3][4] = {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 100, 110, 120}
    };
    
    printf("Search matrix:\n");
    print_matrix(search_matrix, 3);
    
    int search_values[] = {60, 25, 120, 5};
    for (int i = 0; i < 4; i++) {
        int target = search_values[i];
        int found = find_in_matrix(search_matrix, 3, target);
        if (found) {
            printf("Found %d in matrix\n", target);
        } else {
            printf("%d not found in matrix\n", target);
        }
    }
    printf("\n");
    
    // 5. PRACTICAL EXAMPLE - GAME BOARD
    printf("5. PRACTICAL EXAMPLE - GAME BOARD\n");
    printf("----------------------------------------\n");
    
    char chess_board[8][8];
    
    // Initialize chess board
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if ((row + col) % 2 == 0) {
                chess_board[row][col] = '.';  // White squares
            } else {
                chess_board[row][col] = '#';  // Black squares
            }
        }
    }
    
    // Place some pieces
    chess_board[0][0] = 'R';  // Rook
    chess_board[0][1] = 'N';  // Knight
    chess_board[0][4] = 'K';  // King
    chess_board[7][4] = 'k';  // king
    
    printf("Chess board pattern:\n");
    printf("  a b c d e f g h\n");
    for (int row = 0; row < 8; row++) {
        printf("%d ", 8 - row);
        for (int col = 0; col < 8; col++) {
            printf("%c ", chess_board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
    
    // 6. DATA TABLE EXAMPLE
    printf("6. DATA TABLE EXAMPLE\n");
    printf("----------------------------------------\n");
    
    // Student grades table: [student][subject]
    int grades[5][4] = {
        {85, 92, 78, 88},  // Student 0: Math, Science, English, History
        {90, 87, 92, 85},  // Student 1
        {78, 85, 80, 82},  // Student 2
        {95, 89, 94, 91},  // Student 3
        {82, 78, 85, 79}   // Student 4
    };
    
    const char* subjects[] = {"Math", "Science", "English", "History"};
    
    printf("Student Grades Table:\n");
    printf("Student  ");
    for (int j = 0; j < 4; j++) {
        printf("%-8s ", subjects[j]);
    }
    printf("Average\n");
    printf("-------  -------- -------- -------- -------- -------\n");
    
    for (int i = 0; i < 5; i++) {
        printf("   %d     ", i + 1);
        int total = 0;
        for (int j = 0; j < 4; j++) {
            printf("   %2d     ", grades[i][j]);
            total += grades[i][j];
        }
        printf("  %.1f\n", (double)total / 4);
    }
    
    // Subject averages
    printf("\nSubject averages:\n");
    for (int j = 0; j < 4; j++) {
        int total = 0;
        for (int i = 0; i < 5; i++) {
            total += grades[i][j];
        }
        printf("%-8s: %.1f\n", subjects[j], (double)total / 5);
    }
    printf("\n");
    
    // 7. 3D ARRAYS
    printf("7. 3D ARRAYS\n");
    printf("----------------------------------------\n");
    
    // 3D array: [depth][rows][columns]
    int cube[2][3][4] = {
        {  // First layer (depth 0)
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        },
        {  // Second layer (depth 1)
            {13, 14, 15, 16},
            {17, 18, 19, 20},
            {21, 22, 23, 24}
        }
    };
    
    printf("3D Array (2x3x4):\n");
    print_3d_array(cube, 2);
    
    printf("Accessing 3D elements:\n");
    printf("cube[0][1][2] = %d\n", cube[0][1][2]);
    printf("cube[1][2][3] = %d\n", cube[1][2][3]);
    printf("\n");
    
    // 8. PRACTICAL EXAMPLE - RGB IMAGE
    printf("8. PRACTICAL EXAMPLE - RGB IMAGE\n");
    printf("----------------------------------------\n");
    
    // Simulate small RGB image: [height][width][channels]
    unsigned char image[3][4][3];  // 3x4 pixel image, 3 channels (RGB)
    
    // Fill with sample data
    srand((unsigned int)time(NULL));
    for (int h = 0; h < 3; h++) {
        for (int w = 0; w < 4; w++) {
            image[h][w][0] = rand() % 256;  // Red
            image[h][w][1] = rand() % 256;  // Green
            image[h][w][2] = rand() % 256;  // Blue
        }
    }
    
    printf("RGB Image (3x4 pixels):\n");
    for (int h = 0; h < 3; h++) {
        printf("Row %d: ", h);
        for (int w = 0; w < 4; w++) {
            printf("(%3d,%3d,%3d) ", 
                   image[h][w][0], image[h][w][1], image[h][w][2]);
        }
        printf("\n");
    }
    
    // Calculate average color
    int avg_r = 0, avg_g = 0, avg_b = 0;
    for (int h = 0; h < 3; h++) {
        for (int w = 0; w < 4; w++) {
            avg_r += image[h][w][0];
            avg_g += image[h][w][1];
            avg_b += image[h][w][2];
        }
    }
    int total_pixels = 3 * 4;
    printf("Average color: RGB(%d, %d, %d)\n", 
           avg_r / total_pixels, avg_g / total_pixels, avg_b / total_pixels);
    
    printf("\n=== Demo Complete ===\n");
    return 0;
}

// Function implementations

void print_matrix(int matrix[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_square_matrix(int matrix[][3], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void print_char_matrix(char matrix[][BOARD_SIZE], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void initialize_matrix(int matrix[][COLS], int rows, int value) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = value;
        }
    }
}

void fill_matrix_sequential(int matrix[][COLS], int rows) {
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = value++;
        }
    }
}

void transpose_matrix(int source[][3], int dest[][3], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            dest[j][i] = source[i][j];
        }
    }
}

void add_matrices(int a[][3], int b[][3], int result[][3], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiply_matrices(int a[][3], int b[][3], int result[][3], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int find_in_matrix(int matrix[][COLS], int rows, int target) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == target) {
                return 1;  // Found
            }
        }
    }
    return 0;  // Not found
}

void print_3d_array(int arr[][ROWS][COLS], int depth) {
    for (int d = 0; d < depth; d++) {
        printf("Layer %d:\n", d);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%4d ", arr[d][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
