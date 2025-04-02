#include <iostream>

using namespace std;

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { return (b != 0) ? (a / b) : 0; }

void sumArrays(int* A, int* B, int* C, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        C[i] = A[i] + B[i]; 
    }
}

void printArray(const int* arr, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    double (*operations[4])(double, double) = { add, subtract, multiply, divide };
    char symbols[] = { '+', '-', '*', '/' };

    double a, b;
    char op;

    cout << "КАЛЬКУЛЯТОР" << endl;
    cout << "Введіть вираз (наприклад, 5 + 3): ";
    cin >> a >> op >> b;

    bool found = false;
    for (int i = 0; i < 4; i++) 
    {
        if (op == symbols[i]) 
        {
            cout << "Результат: " << operations[i](a, b) << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Помилка: невідома операція!" << endl;
    int size = 5;
    int* A = new int[size];
    int* B = new int[size];
    int* C = new int[size];

    cout << "Введіть елементи масиву A: ";
    for (int i = 0; i < size; i++) cin >> A[i];
    cout << "Введіть елементи масиву B: ";
    for (int i = 0; i < size; i++) cin >> B[i];

    sumArrays(A, B, C, size);
    cout << "\nМАСИВИ\n";
    cout << "Масив A: ";
    printArray(A, size);
    cout << "Масив B: ";
    printArray(B, size);
    cout << "Масив C (сума A + B): ";
    printArray(C, size);

    delete[] A;
    delete[] B;
    delete[] C;

}
