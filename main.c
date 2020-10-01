//
// Created by Ben Schnapp on 10/1/2020.
//

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

int main(){
    //Program 1
    //TODO: test and debug
    #ifdef a
    //Declare variables and I/O locations
    int previous = 0;
    int input = 0;
    unsigned int *p_input;
    p_input = 0x3042FD71;
    LPC_GPIO2->FIODIR &= ~(1<<10); //Push button in input mode
    LPC_GPIO1->FIODIR |= (1<<28); //LED in output mode

    //Main loop
    while(1){
        //read from inputs
        input = (LPC_GPIO1->FIOPIN>>0) & 0x01;

        //write to LEDs
        if ((previous == 0) && (input == 1)){
            //turn on
            LPC_GPIO1->FIOSET |= (1<<28);
            previous = 1;
        }
        else if((previous == 1) && (input == 0)){
            //turn off
            LPC_GPIO1->FIOCLR |= (1<<28);
            previous = 0;
        }
    }
    #endif

    //TODO: Program 2
    #ifdef b
    //declare constants and I/O locations

    //Main loop
    while(1){
        //read from inputs

        //determine which direction joystick is in

        //clear screen

        //print to screen the direction and if pushed down
            //pause for a bit for readability maybe?
    }
    #endif

    //TODO: Program 3
    #ifdef c
    //declare variables and I/O locations
    char str_input[5];
    char str_output[9];
    int int_input = 0;

    //Main loop
    while(1){
        //Clear any values from previous loops
        sprintf(str_input, "");
        sprintf(str_output, "");

        //read user input
        scanf("%s", str_input);

        //convert input to a base10 int
        int_input = atoi(str_input);

        //convert that int to a base2 string and print
        str_output = base10_tobase_2(int_input);
        printf(str_output);

        //TODO: pause for readability
    }
    #endif

    //TODO: Program 4
    #ifdef d
    // declare constants and I/O locations and turn on peripherials

    //Main loop
    while(1){
        //read input

        //do any necessairy conversions

        //write to output
            //pause for readability?

    }
    #endif

}
