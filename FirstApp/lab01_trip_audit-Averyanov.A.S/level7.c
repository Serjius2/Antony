#include <stdio.h>

int main(void)
{
    double distance_km;
    int duration_minutes;
    double battery_capacity_kwh;
    double start_charge_percent;
    double finish_charge_percent;
    double tariff_byn_per_kwh;
    int passengers;

    scanf("%lf", &distance_km);
    scanf("%d %lf %lf %lf %lf %d",
          &duration_minutes,
          &battery_capacity_kwh,
          &start_charge_percent,
          &finish_charge_percent,
          &tariff_byn_per_kwh,
          &passengers);

    double time_hours = duration_minutes / 60.0;
    double energy_used_kwh = battery_capacity_kwh * (start_charge_percent - finish_charge_percent) / 100.0;
    double average_speed_kmh = distance_km / time_hours;
    double consumption_kwh_per_100km = (energy_used_kwh / distance_km) * 100.0;
    double trip_cost_byn = energy_used_kwh * tariff_byn_per_kwh;
    double cost_per_passenger_byn = trip_cost_byn / passengers;

    printf("\n");
    printf("Input data:\n");
    printf("Distance: %.2f km\n", distance_km);
    printf("Duration: %d min\n", duration_minutes);
    printf("Battery capacity: %.2f kWh\n", battery_capacity_kwh);
    printf("Start charge: %.2f %%\n", start_charge_percent);
    printf("Finish charge: %.2f %%\n", finish_charge_percent);
    printf("Tariff: %.2f BYN/kWh\n", tariff_byn_per_kwh);
    printf("Passengers: %d\n", passengers);

    printf("\n");
    printf("Results:\n");
    printf("Time: %.2f h\n", time_hours);
    printf("Energy used: %.2f kWh\n", energy_used_kwh);
    printf("Average speed: %.2f km/h\n", average_speed_kmh);
    printf("Consumption: %.2f kWh / 100km\n", consumption_kwh_per_100km);
    printf("Trip cost: %.2f BYN\n", trip_cost_byn);
    printf("Cost per passenger: %.2f BYN\n", cost_per_passenger_byn);

    return 0;
}
