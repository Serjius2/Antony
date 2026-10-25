#include <stdio.h>
#include <math.h>

// ФУНКЦИЯ ДЛЯ ВВОДА ЗНАЧЕНИЙ КЛИЕНТА 
void input_data(double *distance, double *payload, double *wind, double *battery, double *temperature, int *urgency){
printf("Введите дистанцию (км.): ");
scanf("%lf", distance);

printf("Введите груз (кг.): ");
scanf("%lf", payload);

printf("Введите скорость ветра(км/ч): ");
scanf("%lf", wind);

printf("Введите заряд батареи (%): ");
scanf("%lf", battery);

printf("Введите температуру (C): ");
scanf("%lf", temperature);

printf("Введите срочность (1-3): "); 
scanf(" %d", urgency);
}   


//ОГРАНИЧЕНИЯ ЗНАЧЕНИЙ 
int restrictions_data_check(double distance, double payload, double battery, int urgency){
if (distance <= 0){ 
    printf("Ошибка: Дистанция должна быть больше 0.\n");
return 0;}
if (payload < 0){
    printf("Ошибка: Вес груза не может быть отрицательным.\n");
return 0;}    
if (battery < 0 || battery > 100 ){
    printf("Ошибка: Заряд батареи должен быть от 0 до 100%%.\n");
return 0;}
if (urgency < 1 || urgency > 3){
    printf("Ошибка: Срочность должна быть от 1 до 3.\n");
return 0;}
return 1;
}

//ПОДСЧЕТ ЗНАЧЕНИЙ
void calculate_data(double distance, double payload, double wind, double temperature, 
    double *energy, double *speed, double *ETA, double *risk){            // ETA-Расчетное время прибытия
    double headwind = fmax(wind, 0.0);
    double deviation = fabs(temperature - 20);
    *energy = 2 * distance *(1.2 + 0.25 * payload + 0.08 * headwind + 0.02*deviation);
    *speed = fmax(12.0, 36.0 - 0.7 * headwind - 1.1 * payload);
    *ETA = distance / (*speed) * 60;
    *risk = 2.5 * headwind + 4 * payload + 0.4 * deviation;
}

//ПРИНЯТЬ РЕШЕНИЕ И ОЦЕНИТЬ 
int evaluate_mission(double payload, double wind, double battery, double energy, double risk, int urgency, double ETA) {
    if (payload > 5 || wind > 14) {
        return 0; // REJECT_SAFETY - из-за безопасность
    }
    if (energy + 15 > battery) {
        return 1; // REJECT_BATTERY - из-зи батареи
    }
    if (risk > 45 || (urgency == 3 && ETA > 20)) {
        return 2; // REVIEW (требует ручной проверки)
    }
    return 3; // APPROVED (одобрено)
}
//ФУНКЦИЯ: ВЫВОД РЕЗУЛЬТАТА (требование задания)
void print_result(int decision) {
    printf("\n--- ИТОГОВЫЙ СТАТУС ---\n");
    if (decision == 0) {
        printf("REJECT_SAFETY (Отказ из-за безопасности)\n");
    } else if (decision == 1) {
        printf("REJECT_BATTERY (Отказ из-за батареи)\n");
    } else if (decision == 2) {
        printf("REVIEW (Требует ручной проверки)\n");
    } else if (decision == 3) {
        printf("APPROVED (Доставка одобрена)\n");
    }
}

int main(void){

    double distance, payload, wind, battery, temperature, energy, speed, ETA, risk;
    int urgency;

    // 1. Ввод
    input_data(&distance, &payload, &wind, &battery, &temperature, &urgency);

    // 2. Ограничения (если 0, завершаем работу с ошибкой)
    if (restrictions_data_check(distance, payload, battery, urgency) == 0) {
        return 1; 
    }

    // 3. Расчет
    calculate_data(distance, payload, wind, temperature, &energy, &speed, &ETA, &risk);

    // 4. Решение
    int decision = evaluate_mission(payload, wind, battery, energy, risk, urgency, ETA);

    // 5. Вывод
    print_result(decision);

    return 0;
}


