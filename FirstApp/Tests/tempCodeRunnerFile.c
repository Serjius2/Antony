#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 100000

int main(void)
{
    printf("=== ЧАСТЬ В. ИТЕРАЦИОННЫЙ ПРОЦЕСС (Вариант 1) ===\n");
    
    double z = 0.5;       /* Фиксированное значение z для Варианта 1 из п. 5.3 */
    double eps = 1e-4;    /* Порог точности по п. 5.2 */
    double series_sum = 1.0;  /* t0 = 1 */
    double term = 1.0;        /* текущий член ряда */
    int k = 0;                /* счетчик итераций */
    int converged = 0;

    /* Рекуррентное вычисление t(k+1) = t(k) * z / (k + 1)[cite: 5] */
    while (k < MAX_ITERATIONS) {
        if (fabs(term) <= eps) {
            converged = 1;
            break;
        }

        k++;
        term = term * z / (double)k;
        series_sum += term;
    }

    if (!converged) {
        printf("Предупреждение: достигнут защитный лимит итераций (%d) без сходимости[cite: 5].\n", MAX_ITERATIONS);
    }

    double math_val = exp(z);
    double abs_diff = fabs(series_sum - math_val);

    printf("\n--- РЕЗУЛЬТАТЫ ---\n");
    printf("Параметр z:              %.6f\n", z);
    printf("Порог точности (eps):   %.e\n", eps);
    printf("Приближенное значение:  %.6f\n", series_sum);
    printf("Значение exp(z) (math): %.6f[cite: 5]\n", math_val);
    printf("Абсолютная разность:    %.6f\n", abs_diff);
    printf("Число членов ряда (k):  %d\n", k);

    return 0;
}