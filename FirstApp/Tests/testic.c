#include <stdio.h>
int main(void) {
int D, S, P;
printf("Введите делитель: ");
scanf("%d", &D);
printf("Введите требуемая сумма цифр кода: ");
scanf("%d", &S);
printf("Введение требуемое произведение цифр кода: ");
scanf("%d", &P);
printf("Полученные коды: ");
int discarded = 0;
int min_code = -1;
int found_count =0;
for(int a=1; a<10; a++){
    for(int b=0; b<10; b++){
        for(int c=0; c<10; c++){
            char x = 0;
            
            if(a==b || a==c || b==c){
                x=1;
                discarded++;
                continue;
            }
            if(a + b + c != S){
                x=1;
               discarded++;
                continue;}
            if(a * b * c != P){
                x=1;
                discarded++;
                continue;}
            int num = 100*a+10*b+c;    
            if(num % D !=0 ){
                x=1;
                discarded++;
                continue;
            }
            found_count++;
            printf("%d ", num );
            if(min_code == -1) min_code=num;
        }
    }

}
printf("\nКоличество отброшенных комбинаций из-за повторения:%d", discarded);
printf("\nКоличество найденных кодов:%d", found_count);
printf("\nНаименьший получившийся код:%d", min_code);
}



