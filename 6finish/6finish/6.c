#include <stdio.h>
#include <locale.h>
#include <windows.h>

int task1(int years);
double task2(double x);
int dz(int hours, int minutes);

int main()
{
    int years;
    int leapYear;
    double x;
    double result;
    int hours;
    int minutes;
    int totalMinutes;

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, ".UTF8");

    printf("Введите год: ");
    if (scanf_s("%d", &years) != 1 || years <= 0)
    {
        printf("Ошибка ввода. Год должен быть положительным целым числом.\n");
        return 1;
    }

    leapYear = task1(years);

    if (leapYear == 1)
    {
        printf("Год %d високосный.\n\n", years);
    }
    else
    {
        printf("Год %d не високосный.\n\n", years);
    }

    printf("Введите x: ");
    if (scanf_s("%lf", &x) != 1)
    {
        printf("Ошибка ввода значения x.\n");
        return 1;
    }

    result = task2(x);
    printf("F(x) = %.3f\n\n", result);

    printf("Введите часы (от 0 до 23) и минуты (от 0 до 59):\n");
    if (scanf_s("%d %d", &hours, &minutes) != 2 ||
        hours < 0 || hours > 23 || minutes < 0 || minutes > 59)
    {
        printf("Ошибка ввода времени.\n");
        return 1;
    }
    totalMinutes = dz(hours, minutes);
    printf("%d\n", totalMinutes);

    return 0;
}

int task1(int years)
{
    if ((years % 4 == 0 && years % 100 != 0) || years % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

double task2(double x)
{
    double result;
    result = x <= 1 ? 0.0 : 1.0 / (x + 6);
    return result;
}

int dz(int hours, int minutes)
{
    int totalMinutes;
    int result;

    totalMinutes = hours * 60 + minutes;

    if (totalMinutes == 0)
    {
        result = 0;
    }
    else if (totalMinutes <= 720)
    {
        result = 720 - totalMinutes;
    }
    else
    {
        result = 1440 - totalMinutes;
    }
    return result;
}
