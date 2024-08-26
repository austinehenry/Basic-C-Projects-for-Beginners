#include <stdio.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

void add(double a, double b) {
    printf("Result: %.2f\n", a + b);
}

void subtract(double a, double b) {
    printf("Result: %.2f\n", a - b);
}

void multiply(double a, double b) {
    printf("Result: %.2f\n", a * b);
}

void divide(double a, double b) {
    if (b != 0) {
        printf("Result: %.2f\n", a / b);
    } else {
        printf("Error: Division by zero!\n");
    }
}

void modulus(int a, int b) {
    if (b != 0) {
        printf("Result: %d\n", a % b);
    } else {
        printf("Error: Division by zero!\n");
    }
}

void cm_to_m(double cm) {
    printf("Result: %.2f m\n", cm / 100);
}

void m_to_cm(double m) {
    printf("Result: %.2f cm\n", m * 100);
}

void celsius_to_fahrenheit(double c) {
    printf("Result: %.2f°F\n", (c * 9/5) + 32);
}

void fahrenheit_to_celsius(double f) {
    printf("Result: %.2f°C\n", (f - 32) * 5/9);
}

void power(double base, double exp) {
    printf("Result: %.2f\n", pow(base, exp));
}

void calculate_pi() {
    printf("Result: %.15f\n", PI);
}

void currency_conversion(double amount, int from, int to) {
    double rates[6][6] = {
        {1.0, 0.012, 0.045, 0.011, 1.76, 0.0095},
        {82.0, 1.0, 3.67, 0.92, 146.0, 0.78},
        {22.36, 0.27, 1.0, 0.25, 39.82, 0.21},
        {89.08, 1.08, 4.0, 1.0, 158.27, 0.85},
        {0.57, 0.0068, 0.025, 0.0063, 1.0, 0.0054},
        {104.43, 1.28, 4.82, 1.17, 183.2, 1.0}
    };
    printf("Converted Amount: %.2f\n", amount * rates[from][to]);
}

void area_circle(double r) {
    printf("Area of Circle: %.2f\n", PI * r * r);
}

void area_rectangle(double l, double w) {
    printf("Area of Rectangle: %.2f\n", l * w);
}

void area_square(double s) {
    printf("Area of Square: %.2f\n", s * s);
}

void speed(double distance, double time) {
    printf("Speed: %.2f\n", distance / time);
}

void time_to_seconds(int hours) {
    printf("Time in Seconds: %d\n", hours * 3600);
}

int main() {
    int choice;
    double a, b, amount, r, l, w, s;
    int from, to, hours;
    
    printf("Select an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n");
    printf("6. CM to M\n7. M to CM\n8. Celsius to Fahrenheit\n9. Fahrenheit to Celsius\n");
    printf("10. Power Calculation\n11. Pi Calculation\n12. Currency Conversion\n");
    printf("13. Area of Circle\n14. Area of Rectangle\n15. Area of Square\n");
    printf("16. Speed Calculation\n17. Time (Hours to Seconds)\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
            add(a, b);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
            subtract(a, b);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
            multiply(a, b);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
            divide(a, b);
            break;
        case 5:
            printf("Enter two integers: ");
            scanf("%lf %lf", &a, &b);
            modulus((int)a, (int)b);
            break;
        case 6:
            printf("Enter cm value: ");
            scanf("%lf", &a);
            cm_to_m(a);
            break;
        case 7:
            printf("Enter m value: ");
            scanf("%lf", &a);
            m_to_cm(a);
            break;
        case 8:
            printf("Enter Celsius value: ");
            scanf("%lf", &a);
            celsius_to_fahrenheit(a);
            break;
        case 9:
            printf("Enter Fahrenheit value: ");
            scanf("%lf", &a);
            fahrenheit_to_celsius(a);
            break;
        case 10:
            printf("Enter base and exponent: ");
            scanf("%lf %lf", &a, &b);
            power(a, b);
            break;
        case 11:
            calculate_pi();
            break;
        case 12:
            printf("Enter amount and currency indices (0:INR, 1:USD, 2:AED, 3:EUR, 4:JPY, 5:Pound): ");
            scanf("%lf %d %d", &amount, &from, &to);
            currency_conversion(amount, from, to);
            break;
        case 13:
            printf("Enter radius: ");
            scanf("%lf", &r);
            area_circle(r);
            break;
        case 14:
            printf("Enter length and width: ");
            scanf("%lf %lf", &l, &w);
            area_rectangle(l, w);
            break;
        case 15:
            printf("Enter side: ");
            scanf("%lf", &s);
            area_square(s);
            break;
        case 16:
            printf("Enter distance and time: ");
            scanf("%lf %lf", &a, &b);
            speed(a, b);
            break;
        case 17:
            printf("Enter hours: ");
            scanf("%d", &hours);
            time_to_seconds(hours);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}
