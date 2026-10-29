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
    int loop_count = 0; // Счетчик итераций (для 9 уровня)

    // ОПТИМИЗАЦИЯ УРОВНЯ 9:
    // 1. Ограничение верхних границ: 'a' не может быть больше S и 'a+b' не может быть больше S
    // 2. УДАЛЕН третий цикл по 'c'!
    for (int a = 1; a < 10 && a <= S; a++) {
        for (int b = 0; b < 10 && (a + b) <= S; b++) {
            loop_count++; // Подсчет выполненных итераций оставшихся двух циклов

            // Проверка повторения цифр a и b
            if (a == b) {
                discarded++;
                continue;
            }

            // Рассчитываем цифру 'c' напрямую из условия суммы: a + b + c = S => c = S - a - b
            int c = S - a - b;

            // Проверяем, является ли 'c' допустимой цифрой (от 0 до 9)
            if (c < 0 || c > 9) {
                discarded++;
                continue;
            }

            // Проверяем уникальность 'c' относительно 'a' и 'b'
            if (a == c || b == c) {
                discarded++;
                continue;
            }

            // Проверяем произведение цифр
            if (a * b * c != P) {
                discarded++;
                continue;
            }

            // Формируем трехзначное число
            int num = 100 * a + 10 * b + c;

            // Проверяем делимость на D
            if (num % D != 0) {
                discarded++;
                continue;
            }

            // Если все проверки пройдены:
            found_count++;
            printf("%d ", num);
            if (min_code == -1) min_code = num;
        }
    }

    printf("\nВыполнено итераций (без 3-го цикла): %d\n", loop_count);
    printf("Количество отброшенных комбинаций: %d\n", discarded);
    printf("Количество найденных кодов: %d\n", found_count);
    printf("Наименьший получившийся код: %d\n", min_code);

    return 0;
}