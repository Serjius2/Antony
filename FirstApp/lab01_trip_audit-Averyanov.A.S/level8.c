
#include <stdio.h>
int main(void)
 {

 double distance_km, capacity, start_pct, finish_pct, tariff;
 int duration_minutes, passengers;

 scanf("%lf", &distance_km);

 scanf("%d %lf %lf %lf %lf %d",
 &duration_minutes, &capacity, &start_pct,
 &finish_pct, &tariff, &passengers);

 double time_hours = duration_minutes / 60.0;
 double energy_used = capacity * (start_pct - finish_pct) / 100.0;
 double average_speed = distance_km / time_hours;
 double consumption = energy_used / distance_km * 100.0 ;
 double trip_cost = energy_used * tariff;

 printf("Average speed: %.2f\n", average_speed);
 printf("Consumption: %.2f kWh / 100km \n", consumption);
 printf("Trip cost: %.2f BYN \n", trip_cost);
 
 return 0;

}
