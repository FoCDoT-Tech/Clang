#include <stdio.h>
#include <string.h>

// Function prototypes
void demonstrate_basic_if(void);
void demonstrate_if_else(void);
void demonstrate_else_if_ladder(void);
void demonstrate_nested_if(void);
void demonstrate_switch_case(void);
void demonstrate_practical_examples(void);
char get_grade(int score);
void process_atm_transaction(int choice, double balance);

int main() {
    printf("=== Conditional Statements Demo ===\n\n");
    
    demonstrate_basic_if();
    demonstrate_if_else();
    demonstrate_else_if_ladder();
    demonstrate_nested_if();
    demonstrate_switch_case();
    demonstrate_practical_examples();
    
    printf("✓ All conditional statements demonstrated!\n");
    return 0;
}

void demonstrate_basic_if(void) {
    printf("1. BASIC IF STATEMENT:\n");
    
    int age = 18;
    printf("Age: %d\n", age);
    
    // Simple if statement
    if (age >= 18) {
        printf("✓ Eligible to vote\n");
    }
    
    // Multiple conditions
    int score = 85;
    printf("Score: %d\n", score);
    
    if (score >= 90) {
        printf("✓ Excellent performance!\n");
    }
    
    if (score >= 70 && score < 90) {
        printf("✓ Good performance!\n");
    }
    
    // Condition with expressions
    int x = 10, y = 20;
    if (x + y > 25) {
        printf("✓ Sum %d + %d = %d is greater than 25\n", x, y, x + y);
    }
    
    printf("\n");
}

void demonstrate_if_else(void) {
    printf("2. IF-ELSE STATEMENT:\n");
    
    // Basic if-else
    int number = 7;
    printf("Number: %d\n", number);
    
    if (number % 2 == 0) {
        printf("✓ %d is even\n", number);
    } else {
        printf("✓ %d is odd\n", number);
    }
    
    // Password validation
    char password[] = "secret123";
    char input[] = "secret123";
    
    printf("Password check:\n");
    if (strcmp(password, input) == 0) {
        printf("✓ Access granted\n");
    } else {
        printf("✗ Access denied\n");
    }
    
    // Temperature check
    int temperature = 25;
    printf("Temperature: %d°C\n", temperature);
    
    if (temperature > 30) {
        printf("🔥 It's hot outside!\n");
    } else {
        printf("❄️ Pleasant weather\n");
    }
    
    printf("\n");
}

void demonstrate_else_if_ladder(void) {
    printf("3. ELSE IF LADDER:\n");
    
    // Grade classification
    int score = 78;
    printf("Student score: %d\n", score);
    
    if (score >= 90) {
        printf("Grade: A+ (Outstanding)\n");
    } else if (score >= 80) {
        printf("Grade: A (Excellent)\n");
    } else if (score >= 70) {
        printf("Grade: B (Good)\n");
    } else if (score >= 60) {
        printf("Grade: C (Average)\n");
    } else if (score >= 50) {
        printf("Grade: D (Below Average)\n");
    } else {
        printf("Grade: F (Fail)\n");
    }
    
    // Age category
    int age = 25;
    printf("\nAge category for %d years:\n", age);
    
    if (age < 0) {
        printf("Invalid age\n");
    } else if (age <= 12) {
        printf("Child\n");
    } else if (age <= 19) {
        printf("Teenager\n");
    } else if (age <= 59) {
        printf("Adult\n");
    } else if (age <= 100) {
        printf("Senior\n");
    } else {
        printf("Age seems unrealistic\n");
    }
    
    // BMI classification
    double weight = 70.0, height = 1.75;
    double bmi = weight / (height * height);
    printf("\nBMI: %.1f\n", bmi);
    
    if (bmi < 18.5) {
        printf("Category: Underweight\n");
    } else if (bmi < 25.0) {
        printf("Category: Normal weight\n");
    } else if (bmi < 30.0) {
        printf("Category: Overweight\n");
    } else {
        printf("Category: Obese\n");
    }
    
    printf("\n");
}

void demonstrate_nested_if(void) {
    printf("4. NESTED IF STATEMENTS:\n");
    
    // Login system
    char username[] = "admin";
    char password[] = "pass123";
    char input_user[] = "admin";
    char input_pass[] = "pass123";
    int account_active = 1;
    
    printf("Login attempt:\n");
    printf("Username: %s, Password: %s\n", input_user, input_pass);
    
    if (strcmp(username, input_user) == 0) {
        printf("✓ Username correct\n");
        
        if (strcmp(password, input_pass) == 0) {
            printf("✓ Password correct\n");
            
            if (account_active) {
                printf("✓ Login successful! Welcome %s\n", username);
            } else {
                printf("✗ Account is deactivated\n");
            }
        } else {
            printf("✗ Incorrect password\n");
        }
    } else {
        printf("✗ Username not found\n");
    }
    
    // Discount calculation
    double purchase_amount = 150.0;
    int is_member = 1;
    int years_membership = 3;
    
    printf("\nDiscount calculation:\n");
    printf("Purchase: $%.2f, Member: %s, Years: %d\n", 
           purchase_amount, is_member ? "Yes" : "No", years_membership);
    
    double discount = 0.0;
    
    if (purchase_amount >= 100.0) {
        printf("✓ Qualifies for purchase discount\n");
        
        if (is_member) {
            printf("✓ Member discount applies\n");
            
            if (years_membership >= 5) {
                discount = 0.20;  // 20% for 5+ year members
                printf("✓ VIP member: 20%% discount\n");
            } else if (years_membership >= 2) {
                discount = 0.15;  // 15% for 2+ year members
                printf("✓ Premium member: 15%% discount\n");
            } else {
                discount = 0.10;  // 10% for new members
                printf("✓ New member: 10%% discount\n");
            }
        } else {
            discount = 0.05;  // 5% for non-members
            printf("✓ Non-member: 5%% discount\n");
        }
    } else {
        printf("✗ No discount (minimum $100 required)\n");
    }
    
    double final_amount = purchase_amount * (1.0 - discount);
    printf("Final amount: $%.2f (saved $%.2f)\n", 
           final_amount, purchase_amount - final_amount);
    
    printf("\n");
}

void demonstrate_switch_case(void) {
    printf("5. SWITCH-CASE STATEMENT:\n");
    
    // Day of week
    int day = 3;
    printf("Day number: %d → ", day);
    
    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Invalid day\n");
    }
    
    // Calculator operations
    char operation = '*';
    double a = 15.0, b = 4.0;
    double result = 0.0;
    
    printf("\nCalculator: %.1f %c %.1f = ", a, operation, b);
    
    switch (operation) {
        case '+':
            result = a + b;
            printf("%.1f\n", result);
            break;
        case '-':
            result = a - b;
            printf("%.1f\n", result);
            break;
        case '*':
            result = a * b;
            printf("%.1f\n", result);
            break;
        case '/':
            if (b != 0) {
                result = a / b;
                printf("%.2f\n", result);
            } else {
                printf("Error: Division by zero\n");
            }
            break;
        case '%':
            if (b != 0) {
                result = (int)a % (int)b;
                printf("%.0f\n", result);
            } else {
                printf("Error: Modulo by zero\n");
            }
            break;
        default:
            printf("Error: Unknown operation\n");
    }
    
    // Menu system with fall-through
    int menu_choice = 2;
    printf("\nMenu choice: %d\n", menu_choice);
    
    switch (menu_choice) {
        case 1:
            printf("→ Opening file...\n");
            break;
        case 2:
        case 3:
        case 4:
            printf("→ Processing data (choices 2-4)...\n");
            break;
        case 5:
            printf("→ Saving file...\n");
            break;
        case 0:
            printf("→ Exiting program...\n");
            break;
        default:
            printf("→ Invalid choice\n");
    }
    
    printf("\n");
}

void demonstrate_practical_examples(void) {
    printf("6. PRACTICAL EXAMPLES:\n");
    
    // Grade calculator function
    int scores[] = {95, 87, 76, 64, 45};
    int num_scores = sizeof(scores) / sizeof(scores[0]);
    
    printf("Grade Calculator:\n");
    for (int i = 0; i < num_scores; i++) {
        char grade = get_grade(scores[i]);
        printf("Score %d → Grade %c\n", scores[i], grade);
    }
    
    // ATM simulation
    printf("\nATM Transaction Simulation:\n");
    double balance = 1500.50;
    
    printf("Current balance: $%.2f\n", balance);
    process_atm_transaction(1, balance);  // Check balance
    process_atm_transaction(2, balance);  // Withdraw
    process_atm_transaction(3, balance);  // Deposit
    process_atm_transaction(9, balance);  // Invalid
    
    printf("\n");
}

char get_grade(int score) {
    if (score >= 90) {
        return 'A';
    } else if (score >= 80) {
        return 'B';
    } else if (score >= 70) {
        return 'C';
    } else if (score >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

void process_atm_transaction(int choice, double balance) {
    switch (choice) {
        case 1:
            printf("Balance Inquiry: $%.2f\n", balance);
            break;
        case 2:
            printf("Withdrawal: ");
            if (balance >= 100.0) {
                printf("$100.00 dispensed. New balance: $%.2f\n", balance - 100.0);
            } else {
                printf("Insufficient funds\n");
            }
            break;
        case 3:
            printf("Deposit: $50.00 accepted. New balance: $%.2f\n", balance + 50.0);
            break;
        case 4:
            printf("Transfer: Feature not available\n");
            break;
        default:
            printf("Invalid transaction code: %d\n", choice);
    }
}
