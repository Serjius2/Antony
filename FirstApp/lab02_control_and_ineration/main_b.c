#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 100000

int main(void) {
    double z = 0.0;
    double eps = 1e-4;
    printf("Введите значение z: ");
    scanf("%lf", &z);
    double t = 1.0;       
    double sum = t;       
    int N = 1;            
    
    int converged = 0;    
    int k = 0;            

    printf("--- ЧАСТЬ Б: Итерационный процесс для exp(%.3f) ---\n", z);
    printf("Заданная точность eps = %g\n", eps);

if (eps <= 0.0) {
    printf("Ошибка: значение eps должно быть строго больше 0.\n");
    return 1;
}
    while (k < MAX_ITERATIONS && converged == 0) {
        
        double next_t = t * z / (k + 1);
        
        if (fabs(next_t) <= eps) { 
            converged = 1; 
        } else {
            t = next_t;
            sum += t;
            N++;
        }
        
        k++; 
    }

    if (converged == 1) {
        double math_val = exp(z);
        double abs_diff = fabs(sum - math_val);
        
        printf("\nРяд успешно сошелся!\n");
        printf("Приближенное значение (сумма ряда): %.6f\n", sum);
        printf("Точное значение (math.h):           %.6f\n", math_val);
        printf("Абсолютная разность:                %e\n", abs_diff);
        printf("Число итераций (N):                 %d\n", N);
    } else {
        printf("\nОШИБКА: Достигнут защитный лимит %d итераций.\n", MAX_ITERATIONS);
        printf("Сходимость не достигнута. Проверьте входные данные z или eps.\n");
    }

    return 0;
}