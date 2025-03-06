#include <iostream>
#include <cmath>   // For fabs() function to calculate absolute value
#include <iomanip> // For formatted output using setw() and setprecision()
using namespace std;

// Function to evaluate the equation f(x) = x^3 - 4x - 9
// Modify this function to represent any equation of choice
double f(double x) {
    return (x * x * x) - (4 * x) - 9; // <<<<<----- MODIFY THIS EQUATION
}

// Function to automatically find the interval [a, b] where the root exists
// The interval is found by shifting both a and b with the step size until f(a) and f(b) have opposite signs
void findInterval(double &a, double &b, double step) {
    int maxIter = 1000; // Prevent infinite loop by limiting iterations
    int iter = 0;       // Counter for the number of iterations

    while (f(a) * f(b) >= 0 && iter < maxIter) {
        a += step;  // Increment a by step size
        b += step;  // Increment b by step size
        iter++;
    }

    // If maximum iteration is reached without finding an interval, terminate the program
    if (iter == maxIter) {
        cout << "No interval with opposite signs found" << endl;
        exit(1);  // Exit the program with error code 1
    }
}

// Function to display the header of the iteration table
void displayHeader() {
    cout << setw(12) << "Iteration" << " | "
         << setw(18) << "Interval" << " | "
         << setw(15) << "Midpoint" << " | "
         << setw(15) << "f(c)" << endl;
    cout << string(70, '-') << endl;  // Horizontal line separator
}

int main() {
    // Initial endpoints of the interval
    double a = 0.0;
    double b = 1.0;
    double step = 0.1; // Step size for finding the interval

    // Automatically find the interval where the root exists
    findInterval(a, b, step);

    const double TOL = 0.00001; // Tolerance value to stop iterations
    double c;                  // Midpoint of the interval
    int count = 0;             // Iteration counter

    // Display table header before iterations
    displayHeader();

    // Loop until the difference between a and b is less than the tolerance
    while (fabs(a - b) >= TOL) {
        count++;               // Increment iteration count
        c = (a + b) / 2;       // Calculate midpoint

        // If the function value at midpoint is smaller than the tolerance, stop iteration
        if (fabs(f(c)) < TOL) {
            break;
        }

        // Decide which subinterval to keep based on the signs of f(c) and f(a)
        if (f(c) * f(a) < 0) {
            b = c; // Root is in the left subinterval [a, c]
        } else {
            a = c; // Root is in the right subinterval [c, b]
        }

        // Display the current iteration result in tabular format
        cout << setw(12) << count << " | "
             << "[" << setw(7) << fixed << setprecision(5) << a << ", "
             << setw(7) << b << "] | "
             << setw(15) << c << " | "
             << setw(15) << f(c) << endl;
    }

    // Display the final result after the loop terminates
    cout << "\nApproximate root: " << c << endl;
    cout << "Total iterations: " << count << endl;

    return 0; // Indicate successful execution
}
