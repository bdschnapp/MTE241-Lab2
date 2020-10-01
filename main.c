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
    //TODO: Program 1
    #ifdef a
    //declare constants and I/O locations
    while(1){
        //read from inputs

        //write to LEDs
    }
    #endif

    //TODO: Program 2
    #ifdef b
    //declare constants and I/O locations
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
    //declare constants and I/O locations
    while(1){
        //read user input

        //convert input to a base10 int

        //convert that int to a base2 string and print

        //pause for readability
    }
    #endif

    //TODO: Program 4
    #ifdef d
    // declare constants and I/O locations and turn on peripherials
    while(1){
        //read input

        //do any necessairy conversions

        //write to output
            //pause for readability?

    }
    #endif

}
