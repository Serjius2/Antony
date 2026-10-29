#include <stdio.h>

int main(void) {
    int D, S, P;
    printf("Введите делитель: ");
    scanf("%d", &D);

    if (D == 0) {
        printf("Делитель не может быть равен нулю!\n");
        return 1;
    }

    printf("Введите требуемая сумма цифр кода: ");
    scanf("%d", &S);
    printf("Введение требуемое произведение цифр кода: ");
    scanf("%d", &P);
    
    printf("Полученные коды: ");
    
    int discarded = 0;
    int min_code = -1;
    int found_count = 0;
    int inner_loop_count = 0;

    for(int a = 1; a < 10; a++){
        for(int b = 0; b < 10; b++){
            // ОПТИМИЗАЦИЯ ДЛЯ УРОВНЯ 8: 
            // Если сумма двух первых цифр уже больше целевой S, 
            // то прибавлять единицы c >= 0 бессмысленно — прерываем средний цикл.
            if (a + b > S) {
                break; 
            }

                for(int c = 0; c < 10; c++){    
                    inner_loop_count++;        
                
                if(a == b || a == c || b == c){               
                    discarded++;
                    continue;
                    }
                if(a + b + c != S){               
                    discarded++;
                    continue;
                     }
                if(a * b * c != P){               
                    discarded++;
                    continue;
                }

                int num = 100 * a + 10 * b + c;    
                if(num % D != 0){                
                    discarded++;
                    continue;
                }
                
                found_count++;
                printf("%d ", num);
                if(min_code == -1) min_code = num;
            }
        }
    }

    printf("\nВыполнено итераций внутреннего цикла: %d\n", inner_loop_count);
    printf("Количество отброшенных комбинаций (всего): %d\n", discarded);
    printf("Количество найденных кодов: %d\n", found_count);
    printf("Наименьший получившийся код: %d\n", min_code);

    return 0;
}