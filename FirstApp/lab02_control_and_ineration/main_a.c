#include <stdio.h>
#include <math.h>

#define DOMAIN_EPS 1e-9

int main(void)
{
    double a, b, h;

    /* Ввод a, b, h */
    printf("Введите значения a, b, h: ");
    if (scanf("%lf %lf %lf", &a, &b, &h) != 3) {
        printf("Ошибка: некорректный ввод.\n");
        return 1;
    }

    /* Проверка: a <= b и h > 0, иначе вывод ошибки и конец */
    if (!(a <= b && h > 0)) {
        printf("Ошибка: должно выполняться a <= b и h > 0.\n");
        return 1;
    }

    /* n = floor((b - a) / h) + 1 */
    int n = (int)floor((b - a) / h) + 1;

    /* Ограничение числа точек диапазоном 1..1000 по п. 3.1 */
    if (n < 1) {
        n = 1;
    } else if (n > 1000) {
        printf("Предупреждение: число точек n = %d превышает 1000. Число точек ограничено 1000.\n", n);
        n = 1000;
    }

    int valid = 0, invalid = 0;
    double sum = 0.0;
    double min_y = 0.0, max_y = 0.0;
    int first_valid = 1; /* флаг инициализации min/max первым допустимым y */

    printf("\n%s | %s\n", "x", "y");
    printf("---------------------------------\n");

    for (int i = 0; i < n; i++) {
        double x = a + (double)i * h;

        /* ОДЗ: (10.5*x >= 0) И (|cbrt(x^2) - 1/7| > DOMAIN_EPS) */
        if ((10.5 * x >= 0) && (fabs(cbrt(x * x) - 1.0 / 7.0) > DOMAIN_EPS)) {
            /* y = 2*pi*x - |sin(sqrt(10.5x))| / (cbrt(x^2) - 1/7) */
            double y = 2.0 * acos(-1.0) * x - fabs(sin(sqrt(10.5 * x))) / (cbrt(x * x) - 1.0 / 7.0);

            printf("%.4f | %.6f\n", x, y);

            /* Обновить min, max, sum, valid */
            if (first_valid) {
                min_y = y;
                max_y = y;
                first_valid = 0;
            } else {
                if (y < min_y) min_y = y;
                if (y > max_y) max_y = y;
            }
            sum += y;
            valid++;
        } else {
            printf("%.4f | %s\n", x, "UNDEFINED");
            invalid++;
        }
    }

    /* Вывод valid, invalid, min, max, average */
    printf("\n--- СТАТИСТИКА ---\n");
    printf("Допустимых точек (valid):    %d\n", valid);
    printf("Недопустимых точек (invalid): %d\n", invalid);

    if (valid > 0) {
        printf("Минимум (min):    %.6f\n", min_y);
        printf("Максимум (max):   %.6f\n", max_y);
        printf("Среднее (average): %.6f\n", sum / valid);
    } else {
        printf("Нет допустимых точек: min, max, average не определены.\n");
    }

    return 0;
} 