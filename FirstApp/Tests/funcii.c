#include <stdio.h>

// Объявляем константу Пи
#define PI 3.14159

// 1. Функция для вычисления площади круга
double calculateArea(double radius) {
    return PI * radius * radius;
}

// 2. Функция для вычисления длины окружности
double calculateCircumference(double radius) {
    return 2 * PI * radius;
}

// 3. Функция для красивого вывода результатов
void printResults(double radius, double area, double circumference) {
    printf("\n--- Результаты расчетов ---\n");
    printf("Радиус круга: %.2f\n", radius);
    printf("Площадь круга: %.2f\n", area);
    printf("Длина окружности: %.2f\n", circumference);
}

// Главная функция, с которой начинается выполнение программы
int main() {
    double radius;
    double area;
    double circumference;

    // Запрашиваем данные у пользователя
    printf("Введите радиус круга: ");
    if (scanf("%lf", &radius) != 1 || radius < 0) {
        printf("Ошибка: введено некорректное значение радиуса!\n");
        return 1; // Завершаем программу с кодом ошибки
    }

    // Вызываем функции для расчетов
    area = calculateArea(radius);
    circumference = calculateCircumference(radius);

    // Вызываем функцию для вывода данных
    printResults(radius, area, circumference);

    return 0; // Успешное завершение программы
}