#include <stdio.h>
int main(void)
{
double temperature;
printf("Введите температуру:");
scanf("%lf", &temperature);
int valid = temperature >= -50.0 && temperature <= 60.0;
int outside = temperature < -50.0 || temperature > 60.0;

printf("valid=%d, outside=%d\n", valid, outside);
return 0;
}