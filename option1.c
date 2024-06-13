/*
Option 1 Week 2 peer graded assignment
*/
#include <stdio.h>
#include <assert.h>
//declaring structs
typedef enum month
{
    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
} month;

typedef struct date
{
    month m;
    int d;
} date;

void printDate(date date)
{
    // April-4th, June 6th, Sep 9th, Nov 11 are 30 days month
    // february 28 days
    // using assert for error checking 
    if (date.d > 31)

        assert(0);
    }
    switch (date.m)
    {
    case 1:
        printf("The Day is %s - %d \n", "January", date.d); break;
    case 2:
        if(date.d > 28) 
            assert(0); 
        printf("The Day is %s - %d \n", "Febrary", date.d); break;
    case 3:
        printf("The Day is %s - %d \n", "March", date.d); break;
    case 4:
        if (date.d > 30)
            assert(0);
        printf("The Day is %s - %d \n", "April", date.d); break;
    case 5:
        printf("The Day is %s - %d \n", "May", date.d); break;
    case 6:
        if (date.d > 30)
            assert(0);
        printf("The Day is %s - %d \n", "June", date.d); break;
    case 7:
        printf("The Day is %s - %d \n", "July", date.d); break;
    case 8:
        printf("The Day is %s - %d \n", "August", date.d); break;
    case 9:
        if (date.d > 30)
            assert(0);
        printf("The Day is %s - %d \n", "September", date.d); break;
    case 10:
        printf("The Day is %s - %d \n", "October", date.d); break;
    case 11:
        if (date.d > 30)
            assert(0);
        printf("The Day is %s - %d \n", "November", date.d); break;
    case 12:
        printf("The Day is %s - %d \n", "December", date.d); break;

    default:
        printf("Your month is invalid\n"); 
        assert(0); 
        break;
    }
}

void nextDay(date currentDay)
{
    int newDay; 
    int month = currentDay.m; 
    //checking if the month is february
    if (currentDay.m == 2)
    {
        newDay = (currentDay.d + 1) % 28; 
        if((currentDay.d + 1) > 28) ++month; 
    } else if (currentDay.m ==4 || currentDay.m ==6 || currentDay.m == 9 || currentDay.m == 11) {
        //checking if the month is april,june,september,november
        newDay = (currentDay.d+ 1) % 30; 
        if((currentDay.d + 1) > 30) ++month; 
    } else  {
        //others months 
        newDay = (currentDay.d+ 1) % 31; 
        if((currentDay.d + 1) > 31) ++month; 

    }
    date nextDay;
    nextDay.d = newDay; 
    nextDay.m = month; 
    printDate(nextDay); 
}

int main()
{
    date today; 
    today.d = 28; 
    today.m = 2; 
    printDate(today); 
    nextDay(today);
    return 0;
}
