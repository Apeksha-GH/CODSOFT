#include <iostream>

using namespace std;

// Function prototypes for basic arithmetic operations
void add(double a, double b);
void subtract(double a, double b);
void multiply(double a, double b);
void divide(double a, double b);

int main() {
    double num1, num2;
    char operation, choice = 'y';

    cout << "Welcome to the Unique Calculator!\n";

    // Main loop controlled by 'choice' variable
    while (choice == 'y' || choice == 'Y') {
        // User inputs two numbers
        cout << "\nEnter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;

        // Display operation choices
        cout << "\nChoose an operation to perform:\n";
        cout << "+ for Addition\n";
        cout << "- for Subtraction\n";
        cout << "* for Multiplication\n";
        cout << "/ for Division\n";
        cout << "Enter your choice: ";
        cin >> operation;

        // Perform the chosen operation
        switch(operation) {
            case '+':
                add(num1, num2);
                break;
            case '-':
                subtract(num1, num2);
                break;
            case '*':
                multiply(num1, num2);
                break;
            case '/':
                divide(num1, num2);
                break;
            default:
                cout << "Invalid operation! Please choose +, -, *, or /.\n";
        }

        // Ask if the user wants to perform another calculation
        cout << "\nDo you want to perform another operation? (y/n): ";
        cin >> choice;
    }

    cout << "Thank you for using the Unique Calculator. Goodbye!\n";
    return 0;
}

// Function definitions for basic operations
void add(double a, double b)
{

    double addresult=a+b;
    cout<<"Result:"<<addresult<<endl;

}

void subtract(double a, double b)
{
    double subresult=a-b;
    cout<<"Result:"<<subresult<<endl;
}

void multiply(double a, double b)
{
    double multiplyresult=a*b;
    cout<<"Result:"<<multiplyresult<<endl;
}


void divide(double a, double b) {
    if (b != 0)
    {
        double divideresult=a/b;
        cout << "Result: " << divideresult << endl;
    } else {
        cout << "Error: Division by zero is not allowed!\n";
    }
}
