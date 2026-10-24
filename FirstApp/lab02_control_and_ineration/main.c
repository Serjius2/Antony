#include <stdio.h>
#include<math.h>
int main(void)
{
double x = 0.0;
int f(double x, double *y);
printf("Введите значение x: ");
if (scanf("%lf", &x) !=1) {
    printf("Ошибка ввода!\n");
    return 1; 
}
//работаем с ОДЗ
if (x<0){
    printf("Ошибка: x должен быть неотрицательным ( x>= 0) из-за корня sqrt(10.5 * x).\n");
    return 0;
}

// Вычисляем знаменатель: кубический корень из (x^2) минус 1/7
double denominator = pow(x * x, 1.0 / 3.0) - (1.0 / 7.0);

// Проверка деления на ноль (с учетом погрешности double)
if (fabs(denominator) < 1e-15) {
printf("Ошибка: деление на ноль! Знаменатель равен нулю.\n");
return 0;
}

// Пошаговое вычисление выражения
double numerator = fabs(sin(sqrt(10.5 * x)));
*y = 2.0 * acos(-1.0) * x - (numerator / denominator);

return 1;

    double a, b, h;
    int n, i;
    int points;
     printf("Введите a, b, h: ");
    if (scanf("%lf %lf %lf", &a, &b, &h) != 3) {
        printf("Ошибка ввода\n");
        return 1;
}
if (!(a <= b) || !(h > 0.0)) {
        printf("Ошибка: должно быть a <= b и h > 0\n");
        return 1;
    }
    /* + 1e-9 защищает от погрешности: (1.06-1.0)/0.01 = 5.999999999... */
    n = (int)floor((b - a) / h + 1e-9) + 1;
    if (n < 1) n = 1;
    if (n > points) n = points;
int valid_count = 0, invalid_count = 0;
    double sum_y = 0.0, min_y = 0.0, max_y = 0.0;

    printf("\nn = %d\n", n);
    printf("%-4s %-12s %-14s\n", "i", "x", "y");
    for (i = 0; i < n; i++) {
        double x = a + i * h;
        double y;

        if (f(x, &y)) {
            printf("%-4d %-12.6f %-14.6f\n", i, x, y);
            if (valid_count == 0) {
                min_y = max_y = y;
            } else {
                if (y < min_y) min_y = y;
                if (y > max_y) max_y = y;
            }
            sum_y += y;
            valid_count++;
        } else {
            printf("%-4d %-12.6f UNDEFINED\n", i, x);
            invalid_count++;
        }
    }

    printf("\nvalid_count   = %d\n", valid_count);
    printf("invalid_count = %d\n", invalid_count);
    if (valid_count > 0) {
        printf("min_y         = %.6f\n", min_y);
        printf("max_y         = %.6f\n", max_y);
        printf("average_y     = %.6f\n", sum_y / valid_count);
    } else {
        printf("Допустимых точек нет\n");
    }
 return 0;
}


