#include <stdio.h>
#include <string.h>

int checkTime(int hh, int mm, int payRate){
    if(hh > 11 || hh < 1) return 0; // check for invalid inputs in hours and minutes and check for minimum wage rate
    if(mm > 59 || mm < 0) return 0;
    if(payRate < 7.25) return 0;
    return 1;
}

int toMilTime(int hh, int mm, char s){
    if(s == 's'){ // if the time is in morning then no need to change the time
        return;
    }
    else{
        hh = 12 + hh; // if the time is in the afternoon we have to add 12 to the hour part , no need to change for the minute part
    }
    int mil = 0;
    mil = hh * 100 + mm;
    return mil;
}
int calPayHours(int start, int end){
    int hours = 0, min = 0;
    int smin, shr, emin, ehr;
    shr = start/100;
    smin = start % 100;
    ehr = end/100;
    emin = end % 100;
    if(emin < smin){
        hours += (ehr - shr -1);
        min = (emin+60) - smin; // example: end time: 9:15 and start time :8:30    
                                // min = 15 + 60 - 30 = 45             
        hours += (min % 60);
    }
    else{
        hours += (ehr - shr);
    }
    return hours;
}


int main(){

    int week = 0;
    float payRate, finalTotal = 0.0;
    scanf("%f",&payRate);
    while(1){
        week++;
        int start[5], end[5];
        int i, check, hh, mm, payHours=0;
        float weeklyPayment=0;
        for(i = 0; i < 5; i++){
            printf("Enter the starting hour and minute: ");
            scanf("%.2d %.2d", &hh,&mm);

            check = checkTime(hh, mm, payRate);
            if(!check) printf("Invalid time input!");

            start[i] = toMilTime(hh, mm, 's');

            printf("Enter the ending hour and minute: ");
            scanf("%.2d %.2d", &hh,&mm);

            check = checkTime(hh, mm, payRate);
            if(!check) printf("Invalid time input!");

            end[i] = toMilTime(hh, mm, 'e');
        }
        for(i = 0; i < 5; i++){
            payHours += calPayHours(start[i], end[i]);
            if(week == 1){
                printf("M");
            }
            else if(week == 2){
                printf("T");
            }
            else if(week == 3){
                printf("W");
            }
            else if(week == 4){
                printf("R");
            }
            else if(week == 5){
                printf("F");
            }
            printf("Starting time: %.2d:%.2d , Ending time: %.2d:%.2d", start[i]/100, start[i]%100, end[i]/100, end[i]%100);
        }
        if(payHours > 40){
            weeklyPayment = 40.0 * payRate + ((float)payHours - 40.0) * (payRate * 1.5);
        }
        else{
            weeklyPayment = payHours * payRate;
        }
        finalTotal += weeklyPayment;
        printf("Total no. of hours worked this week is: %.2d & Weekly pay is : %.2f", payHours, weeklyPayment);
        char inp;
        printf("Press Y/y to continue & N/n to terminate the program.")
        scanf("%c", &inp);
        if(inp == 'N' || inp == 'n') break;
    }
    printf("Final pay is: %.2d", finalTotal);

    return 0;
}