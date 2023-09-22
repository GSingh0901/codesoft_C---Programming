#include <iostream>

using namespace std;

int main() {
    char operation;
    float num1, num2, result;

    cout << "\nEnter two numbers "<<endl;
    cout << "Number 1: ";
    cin >> num1 ;
    cout << "Number 2: ";
    cin >> num2 ;
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << result << endl;
            } else {
                cout << "Error! Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operation. Please enter +, -, *, or /." << endl;
    }
    cout <<endl;
    return 0;
}
