/*
 This code show some of the use of the preprocessor
 Date: 04/09/2023
 Author: Hicham Medkour
 This peace of code is going to generate a random a thousand
 of southern male elephant seal weights.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* The aim is to produce a macro that randomly generates a male weight,
   so we use very simple macro here: the minimum and the maximum.
   Note: female weight range is 880-2000 lbs(Pound) (1 lbs=0.453592 kg)*/
#define MAX_ELEPHANT_SEAL_WT_MALE 8800
#define MIN_ELEPHANT_SEAL_WT_MALE 4400

/* The gape between min and max */
#define RANGE         4400

/* We want to generate a population 1000 sample weights */
#define POPULATION    1000

/* Because we want something within the range 4400-8800 */
#define WEIGHT_OVER   rand()% RANGE

/* If WEIGHT_OVER is less than 4400, the actual WEIGHT will be within the range 4400-8800 */
#define WEIGHT        WEIGHT_OVER + MIN_ELEPHANT_SEAL_WT_MALE

/* Here we write multi-line macro to generate the weight samples
and fill the table with them */
#define FILL          for(i=0; i < POPULATION; i++)\
                           data[i]= WEIGHT

/* This is a basic function to print out the data */
void print_data( int d[], int size)
{
   int i;
   for (i=0; i<size; i++)
   {
       printf("%d\t",d[i]); //keep printing on the same line
       if ((i+1)%10 == 0)  printf("\n"); // go to new line after 10 values printed on the same line
   }
}

int main(void)
{
    int i;

    /* None here the advantage of macro:
     we can easily redefine the value of population above
     for exemple: we reuse this code to check for Northern elephant seals */
    int data[POPULATION];

    /*Here when we use the random number generator we want
    each time to call the program to have something different,
    and this "srand(time(0))" allows us to reset the seed based on the system's clock
    and we don't always get the same value*/
    srand(time(0));

    /*Then we call FILL.
    Notice: FILL and all the stuff depends on preprocessor*/
    FILL;

    print_data(data,POPULATION);
    printf("\n\n");

    return 0;
}
