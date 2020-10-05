#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <LPC17xx.h>

#define d

//converts a base10 int to a base2 string
void base10_to_base2(int base10, char *base2) {
    char base2return[30];
    strcpy(base2return, "");
    int divisor = 128;

    for (int i = 0; i < 8; i++) {
        if (base10 - divisor >= 0) {
            (*base2) = (*base2) + 1;
            base10 -= divisor;
        }
        divisor = divisor / 2;
        base2++;
    }
}

void pause() {
    for (int i = 0; i < 2000; i++) {}
}

int main() {
#ifdef a
    //Program 1
    // Turn led on/off if push button is pushed/released

    int previous = 0;
    int input = 0;
    LPC_GPIO2->FIODIR &= ~(1u<<10); //Push button in input mode
    LPC_GPIO1->FIODIR |= (1u<<28); //LED in output mode

    while(1){
        //read from inputs
        input = (LPC_GPIO2->FIOPIN>>10) & 0x01;
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
    //Program 2
    //Read joystick and print out information about it

    int north, south, east, west, pressed;

    //sets all joystick pins to input mode
    LPC_GPIO1->FIODIR &= ~(1u<<20);
    LPC_GPIO1->FIODIR &= ~(1u<<23);
    LPC_GPIO1->FIODIR &= ~(1u<<24);
    LPC_GPIO1->FIODIR &= ~(1u<<25);
    LPC_GPIO1->FIODIR &= ~(1u<<26);

    while(1){
        north = !((LPC_GPIO1->FIOPIN>>23) & 0x01); // a 23
        east = !((LPC_GPIO1->FIOPIN>>24) & 0x01); // b 24
        south = !((LPC_GPIO1->FIOPIN>>25) & 0x01); // d 25
        west = !((LPC_GPIO1->FIOPIN>>26) & 0x01); // c 26
        pressed = ((LPC_GPIO1->FIOPIN>>20) & 0x01); //cntr 20

        if (north){
            printf("North ");
        }
        else if(south){
            printf("South ");
        }
        else if(east){
            printf("East ");
        }
        else if(west){
            printf("West ");
        }
        else{
            printf("Centered ");
        }

        if(pressed){
            printf("and not pushed down \n");
        }
        else{
            printf("and pushed down \n");
        }
        pause();
    }
#endif


#ifdef c
    //Program 3
    //Declare variables
    char str_input[5];
    int int_input = 0;

    //Set LEDs to output mode
    LPC_GPIO1->FIODIR |= (1u<<28);
    LPC_GPIO1->FIODIR |= (1u<<29);
    LPC_GPIO1->FIODIR |= (1u<<31);
    LPC_GPIO2->FIODIR |= (1u<<2);
    LPC_GPIO2->FIODIR |= (1u<<3);
    LPC_GPIO2->FIODIR |= (1u<<4);
    LPC_GPIO2->FIODIR |= (1u<<5);
    LPC_GPIO2->FIODIR |= (1u<<6);
    while(1){
        //Clear any values from previous loops
        sprintf(str_input, "");

        //read user input

        scanf("%s", str_input);
        //convert input to a base10 int
        int_input = atoi(str_input);
        char str_output[] = {'0','0','0','0','0','0','0','0'};
        //convert that int to a base2 string and print
        base10_to_base2(int_input, &str_output[0]);

        //using the binarry array, set the LEDs based on the input
        if(str_output[7] == '1'){
              LPC_GPIO1->FIOSET |= (1u<<28);
        } else {
              LPC_GPIO1->FIOCLR |= (1u<<28);
        }
        if(str_output[6] == '1'){
              LPC_GPIO1->FIOSET |= (1u<<29);
        } else {
              LPC_GPIO1->FIOCLR |= (1u<<29);
        }
        if(str_output[5] == '1'){
              LPC_GPIO1->FIOSET |= (1u<<31);
        } else {
              LPC_GPIO1->FIOCLR |= (1u<<31);
        }
        if(str_output[4] == '1'){
              LPC_GPIO2->FIOSET |= (1u<<2);
        } else {
              LPC_GPIO2->FIOCLR |= (1u<<2);
        }
        if(str_output[3] == '1'){
              LPC_GPIO2->FIOSET |= (1u<<3);
        } else {
              LPC_GPIO2->FIOCLR |= (1u<<3);
        }
        if(str_output[2] == '1'){
              LPC_GPIO2->FIOSET |= (1u<<4);
        } else {
              LPC_GPIO2->FIOCLR |= (1u<<4);
        }
        if(str_output[1] == '1'){
              LPC_GPIO2->FIOSET |= (1u<<5);
        } else {
              LPC_GPIO2->FIOCLR |= (1u<<5);
        }
        if(str_output[0] == '1'){
              LPC_GPIO2->FIOSET |= (1u<<6);
        } else {
              LPC_GPIO2->FIOCLR |= (1u<<6);
        }
        pause();
    }
#endif


#ifdef d
    //Program 4
    //Read analogue input and print output

    //set up adc
    LPC_SC->PCONP |= (1 << 12);
    LPC_PINCON->PINSEL1 &= ~(0x03 << 18);
    LPC_PINCON->PINSEL1 |= ~(0x01 << 18);

    LPC_ADC->ADCR &= 0x00; //set all analogue digital conversion register values to zero
    LPC_ADC->ADCR |= (0x01 << 2); //set input channel
    LPC_ADC->ADCR |= (0x100 << 8); //set buf clock speed
    LPC_ADC->ADCR |= (0x01 << 21); //enable power to ADc circuit
    int result;
    while (1) {
        LPC_ADC->ADCR |= (0x01 << 24); //start the adc conversion
        while ((LPC_ADC->ADGDR & (0x1 << 31)) == 0x00); //wait for adc to finish
        result = (LPC_ADC->ADGDR >> 4) & 0xfff; //get result from adc

        printf("adc: %d\n", result); //printf adc result
    }
#endif
}
