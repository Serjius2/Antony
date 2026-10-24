#include <stdio.h>
int main(void)
{
double left;
double right;
char operation;

printf("Введите: число операцию число: ");
if (scanf("%lf %c %lf", &left, &operation, &right) != 3) {
printf("ошибка.\n");
return 1;
}
 
double result;
switch (operation){
 case '+':
    result = left + right;
    break;
 case '-':
    result = left - right;
    break;
 case '*':
    result = left * right;
    break;
 case '/':
    if (right ==0.0) {
        printf("Ошибка при нуле. \n");
        return 1;
    }  
    result = left / right;
    break;
    default:
    printf("Не поддерживаемая операция.\n");
    return 1;

}
printf("Результат: %.3f\n", result);

    return 0;
}