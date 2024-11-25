#include <iostream>
#include <fstream>
using namespace std;

// Функція для обчислення значення y для від'ємних x
double calculateYNegative(double x, double n)
{
    if (n <= 2)
    {
        // Якщо n занадто мале для виконання циклу
        return 1.0;
    }

    double y = 1.0;
    for (int j = 2; j <= n - 2; j++)
    {
        y *= (j * j);
    }
    return y;
}

// Функція для обчислення значення y для додатних x
double calculateYPositive(double x, double n)
{
    double y = 0.0;
    for (int i = 0; i <= n - 1; i++)
    {
        double product = 1.0;
        for (int j = 0; j <= n - 1; j++)
        {
            product *= (x + i * i + j); // Виправлення множення
        }
        y += product;
    }
    return y;
}

// Введення значень змінних з клавіатури
void inputValues(double &a, double &b, double &h, double &n)
{
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter h: ";
    cin >> h;
    cout << "Enter n: ";
    cin >> n;
}

// Обробка значень та виведення результатів
void processValues(double a, double b, double h, double n)
{
    ofstream outFile("results.txt"); // Створення або відкриття файлу для запису

    if (!outFile)
    {
        cerr << "Error opening file!" << endl; // Перевірка на помилки при відкритті файлу
        return;
    }

    for (double x = a; x <= b; x += h)
    {
        double y = 0.0;
        if (x < 0)
        {
            y = calculateYNegative(x, n);
        }
        else
        {
            y = calculateYPositive(x, n);
        }

        // Виведення результатів на екран
        cout << "x = " << x << ", y = " << y << endl;

        // Запис результату у файл
        outFile << "x = " << x << ", y = " << y << endl;
    }

    outFile.close(); // Закриття файлу після запису
}

int main()
{
    double a, b, h, n;
    inputValues(a, b, h, n);   // Введення значень
    processValues(a, b, h, n); // Обробка та запис у файл
    return 0;
}
