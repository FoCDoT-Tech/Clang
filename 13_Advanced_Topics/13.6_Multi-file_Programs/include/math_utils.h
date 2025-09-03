#ifndef MATH_UTILS_H
#define MATH_UTILS_H

// Mathematical constants
#define PI 3.14159265359

// Point structures
typedef struct {
    double x, y;
} Point2D;

typedef struct {
    double x, y, z;
} Point3D;

// Function declarations
double calculate_area(double radius);
double calculate_volume(double radius, double height);
int factorial(int n);
double distance_2d(const Point2D* p1, const Point2D* p2);
double distance_3d(const Point3D* p1, const Point3D* p2);

#endif /* MATH_UTILS_H */
