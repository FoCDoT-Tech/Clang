#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function prototypes
void demonstrate_basic_math(void);
void demonstrate_trigonometry(void);
void demonstrate_logarithmic_exponential(void);
void demonstrate_floating_point_utils(void);
void demonstrate_practical_applications(void);

int main(void) {
    printf("=== Math Library Demo ===\n\n");
    
    demonstrate_basic_math();
    demonstrate_trigonometry();
    demonstrate_logarithmic_exponential();
    demonstrate_floating_point_utils();
    demonstrate_practical_applications();
    
    printf("=== Demo Complete ===\n");
    return 0;
}

void demonstrate_basic_math(void) {
    printf("1. BASIC MATH FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    double values[] = {-5.7, -2.3, 0.0, 2.3, 5.7, 9.8};
    int num_values = sizeof(values) / sizeof(values[0]);
    
    printf("Value\t| fabs\t| ceil\t| floor\t| sqrt\n");
    printf("--------|-------|-------|-------|-------\n");
    
    for (int i = 0; i < num_values; i++) {
        double val = values[i];
        printf("%.1f\t| %.1f\t| %.1f\t| %.1f\t| ", 
               val, fabs(val), ceil(val), floor(val));
        
        if (val >= 0) {
            printf("%.2f\n", sqrt(val));
        } else {
            printf("NaN\n");
        }
    }
    
    // Power function demonstrations
    printf("\nPower function examples:\n");
    printf("pow(2, 3) = %.1f\n", pow(2, 3));
    printf("pow(4, 0.5) = %.2f\n", pow(4, 0.5));
    printf("pow(10, -2) = %.4f\n", pow(10, -2));
    printf("pow(-2, 3) = %.1f\n", pow(-2, 3));
    
    // Modulo for floating point
    printf("\nFloating-point modulo:\n");
    printf("fmod(7.5, 2.3) = %.2f\n", fmod(7.5, 2.3));
    printf("fmod(-7.5, 2.3) = %.2f\n", fmod(-7.5, 2.3));
    printf("fmod(7.5, -2.3) = %.2f\n", fmod(7.5, -2.3));
    
    printf("\n");
}

void demonstrate_trigonometry(void) {
    printf("2. TRIGONOMETRIC FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    // Common angles in radians
    double angles[] = {0.0, M_PI/6, M_PI/4, M_PI/3, M_PI/2, M_PI, 2*M_PI};
    const char* angle_names[] = {"0°", "30°", "45°", "60°", "90°", "180°", "360°"};
    int num_angles = sizeof(angles) / sizeof(angles[0]);
    
    printf("Angle\t| sin\t| cos\t| tan\n");
    printf("--------|-------|-------|-------\n");
    
    for (int i = 0; i < num_angles; i++) {
        double angle = angles[i];
        printf("%s\t| %.3f\t| %.3f\t| ", 
               angle_names[i], sin(angle), cos(angle));
        
        if (fabs(cos(angle)) > 1e-10) {
            printf("%.3f\n", tan(angle));
        } else {
            printf("inf\n");
        }
    }
    
    // Inverse trigonometric functions
    printf("\nInverse trigonometric functions:\n");
    double values[] = {-1.0, -0.5, 0.0, 0.5, 1.0};
    
    for (int i = 0; i < 5; i++) {
        double val = values[i];
        printf("asin(%.1f) = %.3f rad (%.1f°)\n", 
               val, asin(val), asin(val) * 180.0 / M_PI);
        printf("acos(%.1f) = %.3f rad (%.1f°)\n", 
               val, acos(val), acos(val) * 180.0 / M_PI);
    }
    
    // atan2 for quadrant-aware arctangent
    printf("\natan2 examples (y, x):\n");
    printf("atan2(1, 1) = %.3f rad (%.1f°) - First quadrant\n", 
           atan2(1, 1), atan2(1, 1) * 180.0 / M_PI);
    printf("atan2(1, -1) = %.3f rad (%.1f°) - Second quadrant\n", 
           atan2(1, -1), atan2(1, -1) * 180.0 / M_PI);
    printf("atan2(-1, -1) = %.3f rad (%.1f°) - Third quadrant\n", 
           atan2(-1, -1), atan2(-1, -1) * 180.0 / M_PI);
    printf("atan2(-1, 1) = %.3f rad (%.1f°) - Fourth quadrant\n", 
           atan2(-1, 1), atan2(-1, 1) * 180.0 / M_PI);
    
    // Hyperbolic functions
    printf("\nHyperbolic functions:\n");
    double hyp_values[] = {0.0, 0.5, 1.0, 2.0};
    
    for (int i = 0; i < 4; i++) {
        double val = hyp_values[i];
        printf("sinh(%.1f) = %.3f, cosh(%.1f) = %.3f, tanh(%.1f) = %.3f\n",
               val, sinh(val), val, cosh(val), val, tanh(val));
    }
    
    printf("\n");
}

void demonstrate_logarithmic_exponential(void) {
    printf("3. LOGARITHMIC & EXPONENTIAL FUNCTIONS\n");
    printf("----------------------------------------\n");
    
    // Exponential function
    printf("Exponential function (e^x):\n");
    double exp_values[] = {0.0, 1.0, 2.0, -1.0, -2.0};
    
    for (int i = 0; i < 5; i++) {
        double val = exp_values[i];
        printf("exp(%.1f) = %.6f\n", val, exp(val));
    }
    
    // Natural logarithm
    printf("\nNatural logarithm (ln):\n");
    double log_values[] = {1.0, M_E, 10.0, 100.0, 0.1};
    
    for (int i = 0; i < 5; i++) {
        double val = log_values[i];
        printf("log(%.6f) = %.6f\n", val, log(val));
    }
    
    // Base-10 logarithm
    printf("\nBase-10 logarithm:\n");
    double log10_values[] = {1.0, 10.0, 100.0, 1000.0, 0.1, 0.01};
    
    for (int i = 0; i < 6; i++) {
        double val = log10_values[i];
        printf("log10(%.2f) = %.6f\n", val, log10(val));
    }
    
    // Relationship between exp and log
    printf("\nVerifying exp/log relationships:\n");
    double test_val = 5.0;
    printf("Original value: %.1f\n", test_val);
    printf("exp(log(%.1f)) = %.6f\n", test_val, exp(log(test_val)));
    printf("log(exp(%.1f)) = %.6f\n", test_val, log(exp(test_val)));
    
    // Change of base formula: log_b(x) = log(x) / log(b)
    printf("\nChange of base (log base 2):\n");
    double base2_values[] = {1.0, 2.0, 4.0, 8.0, 16.0};
    
    for (int i = 0; i < 5; i++) {
        double val = base2_values[i];
        double log2_val = log(val) / log(2.0);
        printf("log2(%.1f) = %.6f\n", val, log2_val);
    }
    
    printf("\n");
}

void demonstrate_floating_point_utils(void) {
    printf("4. FLOATING-POINT UTILITIES\n");
    printf("----------------------------------------\n");
    
    // modf - split into integer and fractional parts
    printf("modf - split into integer and fractional parts:\n");
    double modf_values[] = {3.14159, -2.718, 42.0, -0.5};
    
    for (int i = 0; i < 4; i++) {
        double val = modf_values[i];
        double integer_part, fractional_part;
        
        fractional_part = modf(val, &integer_part);
        printf("modf(%.5f) -> integer: %.1f, fractional: %.5f\n",
               val, integer_part, fractional_part);
    }
    
    // frexp - extract mantissa and exponent
    printf("\nfrexp - extract mantissa and exponent:\n");
    printf("(represents number as mantissa * 2^exponent)\n");
    double frexp_values[] = {1.0, 2.0, 3.0, 8.0, 1024.0};
    
    for (int i = 0; i < 5; i++) {
        double val = frexp_values[i];
        int exponent;
        double mantissa = frexp(val, &exponent);
        
        printf("frexp(%.1f) -> mantissa: %.6f, exponent: %d\n",
               val, mantissa, exponent);
        printf("  Verification: %.6f * 2^%d = %.1f\n",
               mantissa, exponent, mantissa * pow(2, exponent));
    }
    
    // ldexp - construct from mantissa and exponent
    printf("\nldexp - construct from mantissa and exponent:\n");
    double mantissas[] = {0.5, 0.75, 0.625};
    int exponents[] = {3, 4, 6};
    
    for (int i = 0; i < 3; i++) {
        double result = ldexp(mantissas[i], exponents[i]);
        printf("ldexp(%.3f, %d) = %.1f\n", mantissas[i], exponents[i], result);
    }
    
    printf("\n");
}

void demonstrate_practical_applications(void) {
    printf("5. PRACTICAL APPLICATIONS\n");
    printf("----------------------------------------\n");
    
    // Distance calculation
    printf("Distance between two points:\n");
    double x1 = 1.0, y1 = 2.0;
    double x2 = 4.0, y2 = 6.0;
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    printf("Distance from (%.1f, %.1f) to (%.1f, %.1f) = %.2f\n",
           x1, y1, x2, y2, distance);
    
    // Circle calculations
    printf("\nCircle calculations:\n");
    double radius = 5.0;
    double circumference = 2 * M_PI * radius;
    double area = M_PI * pow(radius, 2);
    printf("Circle with radius %.1f:\n", radius);
    printf("  Circumference = %.2f\n", circumference);
    printf("  Area = %.2f\n", area);
    
    // Angle conversion
    printf("\nAngle conversions:\n");
    double degrees = 45.0;
    double radians = degrees * M_PI / 180.0;
    printf("%.1f degrees = %.4f radians\n", degrees, radians);
    printf("%.4f radians = %.1f degrees\n", radians, radians * 180.0 / M_PI);
    
    // Compound interest calculation
    printf("\nCompound interest calculation:\n");
    double principal = 1000.0;
    double rate = 0.05;  // 5% annual rate
    int years = 10;
    double amount = principal * pow(1 + rate, years);
    printf("Principal: $%.2f, Rate: %.1f%%, Years: %d\n", 
           principal, rate * 100, years);
    printf("Final amount: $%.2f\n", amount);
    printf("Interest earned: $%.2f\n", amount - principal);
    
    // Quadratic formula
    printf("\nQuadratic formula (ax² + bx + c = 0):\n");
    double a = 1.0, b = -5.0, c = 6.0;
    double discriminant = pow(b, 2) - 4 * a * c;
    
    printf("Equation: %.1fx² + %.1fx + %.1f = 0\n", a, b, c);
    printf("Discriminant = %.1f\n", discriminant);
    
    if (discriminant >= 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots: x₁ = %.2f, x₂ = %.2f\n", root1, root2);
    } else {
        printf("Complex roots (discriminant < 0)\n");
    }
    
    // Sine wave generation (for plotting/signal processing)
    printf("\nSine wave values (0° to 360° in 45° steps):\n");
    printf("Angle\t| sin(x)\t| cos(x)\n");
    printf("--------|---------------|---------------\n");
    
    for (int angle_deg = 0; angle_deg <= 360; angle_deg += 45) {
        double angle_rad = angle_deg * M_PI / 180.0;
        printf("%d°\t| %6.3f\t| %6.3f\n", 
               angle_deg, sin(angle_rad), cos(angle_rad));
    }
    
    printf("\n");
}
