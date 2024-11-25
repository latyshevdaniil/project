#include <iostream>
using namespace std;

double calculateYNegative(double x, double n)
{
    double y = 1.0;
    for (int j = 2; j <= n - 2; j++)
    {
        y *= (j * j);
    }
    return y;
}

double calculateYPositive(double x, double n)
{
    double y = 0.0;
    for (int i = 0; i <= n - 1; i++)
    {
        double product = 1.0;
        for (int j = 0; j <= n - 1; j++)
        {
            product = (x + i * i + j);
        }
        y += product;
    }
    return y;
}

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

void processValues(double a, double b, double h, double n)
{
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
        cout << "x = " << x << ", y = " << y << endl;
    }
}

int main()
{
    double a, b, h, n;
    inputValues(a, b, h, n);
    processValues(a, b, h, n);
    return 0;
}