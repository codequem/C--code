#include <iostream>
#include <iomanip>
#include <cmath>

double func(double x, double a, double b)
{
    return sqrt(pow(x, 2) + a) + sqrt(pow(b - x, 2) + 1);
}

double func_derivative(double x, double a, double b)
{
    return (x / sqrt(pow(x, 2) + a)) - ((b - x) / sqrt(pow(b - x, 2) + 1));
}

double gradient_descent(double initial_x, double a, double b, double learning_rate, int iterations)
{
    double x = initial_x;
    for (int i = 0; i < iterations; ++i)
    {
        x -= learning_rate * func_derivative(x, a, b);
    }
    return x;
}

int main()
{
    double a, b;
    std::cin >> a;
    std::cin >> b;

    double initial_guess = 0;

    double learning_rate = 0.01;

    int iterations = 500000;

    double result = gradient_descent(initial_guess, a, b, learning_rate, iterations);
    double min_value = func(result, a, b);
    printf("%0.6f", min_value);
    return 0;
}
