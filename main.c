#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lpc17xx.h>

#define a 1

//converts a base10 int to a base2 string
const char * base10_to_base2(int base10){
    char base2[30];
    strcpy(base2, "");
    char base2return[30];
    strcpy(base2return, "");
    int i = 0;

    //makes a binary string in reverse order
    while(base10 != 0){
        char str[1];
        int c = (base10%2);
        base10 = base10/2;
        sprintf(str, "%d", c);
        strcat(base2, str);
        i++;
    }
    //Reverses the string
    for(int j = 0; j < i; j ++){
        char str[1];
        sprintf(str, "%c", base2[i-j-1]);
        strcat(base2return, str);
    }
    return base2return;
}

void pause(){
    for(int i = 0; i < 2000; i++){}
}

//TODO: test and debug
int main(){

    #ifdef a
    //Program 1 Turn led on/off if push button is pushed/released
    //Declare variables and I/O locations
    int previous = 0;
    int input = 0;
    LPC_GPIO2->FIODIR &= ~(1u<<10); //Push button in input mode
    LPC_GPIO1->FIODIR |= (1u<<28); //LED in output mode

    //Main loop
    while(1){
        //read from inputs
        input = (LPC_GPIO1->FIOPIN>>10) & 0x01;

        //write to LEDs
        if ((previous == 0) && (input == 1)){
            //turn on
            LPC_GPIO1->FIOSET |= (1u<<28);
            previous = 1;
        }
        else if((previous == 1) && (input == 0)){
            //turn off
            LPC_GPIO1->FIOCLR |= (1u<<28);
            previous = 0;
        }
        pause();
    }
    #endif


    #ifdef b
    //Program 2 read joystick and print out information about it
    //declare constants and I/O locations
    int north, south, east, west, pushed;

    //sets all joystick pins to input mode
    LPC_GPIO1->FIODIR &= ~(1u<<20);
    LPC_GPIO1->FIODIR &= ~(1u<<23);
    LPC_GPIO1->FIODIR &= ~(1u<<24);
    LPC_GPIO1->FIODIR &= ~(1u<<25);
    LPC_GPIO1->FIODIR &= ~(1u<<26);

    //Main loop
    while(1){
        north = (LPC_GPIO1->FIOPIN>>24) & 0x01; // b 24
        south = (LPC_GPIO1->FIOPIN>>25) & 0x01; // d 25
        east = (LPC_GPIO1->FIOPIN>>26) & 0x01; // c 26
        west = (LPC_GPIO1->FIOPIN>>23) & 0x01; // a 23
        pushed = (LPC_GPIO1->FIOPIN>>20) & 0x01; //cntr 20

        if (north){
            printf("North    ");
        }
        else if(south){
            printf("South    ");
        }
        else if(east){
            printf("East     ");
        }
        else if(west){
            printf("West     ")
        }
        else{
            printf("Centered ")
        }

        if(pushed){
            printf("and pushed down");
        }
        else{
            printf("and not pushed down");
        }
        pause();
    }
    #endif


    #ifdef c
    //Program 3, take base10 int user input and convert to base2 string and print
    //Declare variables
    char str_input[5];
    char str_output[9];
    int int_input = 0;

    //Main loop
    while(1){
        //Clear any values from previous loops
        sprintf(str_input, "");
        sprintf(str_output, "");

        //read user input
        //TODO: verify that scanf works with LPC1768
        scanf("%s", str_input);

        //convert input to a base10 int
        int_input = atoi(str_input);

        //convert that int to a base2 string and print
        str_output = base10_tobase_2(int_input);
        printf(str_output);

        pause();
    }
    #endif


    #ifdef d
    //TODO: Program 4
    //Read analogue input and print output

    #endif

}
