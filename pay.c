#include <stdio.h>
#include <string.h>

int checkTime(int hh, int mm, int payRate){
    if(hh > 11 || hh < 1) return 0; // check for invalid zuts in hours and minutes and check for minimum wage rate
    if(mm > 59 || mm < 0) return 0;
    if(payRate < 7.25) return 0;
    return 1;
}

int toMilTime(int hh, int mm, char s){
    if(s == 's'){ // if the time is in morning then no need to change the time
        return hh*100+mm;
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
    printf("Enter the pay rate: \n");
    scanf("%f",&payRate);
    int start[5], end[5];
    int i, check, hh, mm, payHours=0;
    float weeklyPayment=0;
    int z;
    while(1){
        week++;
        for(i = 0; i < 5; i++){
            printf("Enter the starting hour and minute: ");
            scanf("%2d:%2d", &hh,&mm);

            check = checkTime(hh, mm, payRate);
            if(!check) printf("Invalid time zut!");

            start[i] = toMilTime(hh, mm, 's');

            printf("Enter the ending hour and minute: ");
            scanf("%2d:%2d", &hh,&mm);

            check = checkTime(hh, mm, payRate);
            if(!check) printf("Invalid time zut!");

            end[i] = toMilTime(hh, mm, 'e');
        }
        for(i = 0; i < 5; i++){
            payHours += calPayHours(start[i], end[i]);
            if(i == 0){
                printf("M\n");
            }
            else if(i == 1){
                printf("T\n");
            }
            else if(i == 2){
                printf("W\n");
            }
            else if(i == 3){
                printf("R\n");
            }
            else if(i == 4){
                printf("F\n");
            }
            printf("Starting time: %d , Ending time: %d\n", start[i], end[i]);
        }
        if(payHours > 40){
            weeklyPayment = 40.0 * payRate + ((float)payHours - 40.0) * (payRate * 1.5);
        }
        else{
            weeklyPayment = payHours * payRate;
        }
        finalTotal += weeklyPayment;
        printf("Total no. of hours worked this week is: %d & Weekly pay is : %.2f\n", payHours, weeklyPayment);
        payHours = 0; weeklyPayment = 0;
        printf("Press 1 to continue & 0 to terminate the program.\n");
        scanf("%d",&z);
        //printf("hello bro\n");
        if(z == 0) break;
    }
    printf("Final pay is: %2f\n", finalTotal);

    return 0;
}