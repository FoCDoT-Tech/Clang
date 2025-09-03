#include "math_utils.h"
#include <math.h>

double calculate_area(double radius) {
    return PI * radius * radius;
}

double calculate_volume(double radius, double height) {
    return calculate_area(radius) * height;
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

double distance_2d(const Point2D* p1, const Point2D* p2) {
    if (!p1 || !p2) return 0.0;
    
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy);
}

double distance_3d(const Point3D* p1, const Point3D* p2) {
    if (!p1 || !p2) return 0.0;
    
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    double dz = p1->z - p2->z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}
