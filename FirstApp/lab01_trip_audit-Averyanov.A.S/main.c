#include <stdio.h>
int main(void)
{
    double distance_km;
    unsigned int duration_minutes;
    double battery_capacity_kwh;
    double start_charge_percent;
    double finish_charge_percent;
    double tariff_byn_per_kwh;
    unsigned int passengers;
   
    printf("Введите дистанцию: ");
    scanf("%lf", &distance_km);

    printf("Введите время: ");
    scanf("%u", &duration_minutes);

    printf("Введите емкость аккумулятора: ");
    scanf("%lf", &battery_capacity_kwh);

    printf("Введите нач., проценты аккумулятора: ");
    scanf("%lf", &start_charge_percent);

    printf("Введите кон,. проценты аккумулятора: ");
    scanf("%lf", &finish_charge_percent);

    printf("Введите стоимость энергии: ");
    scanf("%lf", &tariff_byn_per_kwh);

    printf("Введите количество пассажиров: ");
    scanf("%u", &passengers);

    double time_hours =(double)duration_minutes / 60;
    double energy_used_kwh = battery_capacity_kwh * (start_charge_percent - finish_charge_percent) / 100.0;
    double average_speed_kmh = distance_km / time_hours;
    double consumption_kwh_per_100km = energy_used_kwh / distance_km * 100.0;
    double trip_cost_byn = energy_used_kwh * tariff_byn_per_kwh;
    double cost_per_passenger_byn = trip_cost_byn / passengers;

    printf("\n");
    printf("Time_hours: %.2f h\n", time_hours);
    printf("Energy used: %.2f kWh\n", energy_used_kwh);
    printf("Average speed: %.2f km/h\n", average_speed_kmh);
    printf("Consumption: %.2f kWh / 100km\n", consumption_kwh_per_100km);
    printf("Trip cost: %.2f BYN\n", trip_cost_byn);
    printf("Cost per passenger: %.2f BYN\n", cost_per_passenger_byn);
    
    return 0;
}