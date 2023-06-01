// multiplication of 8 bit numbers on pic18f
// GROUP_A_3_1
#include <stdlib.h>
#include <stdio.h>
#include<p18f4550.h>
// #include <xc.h>


void main(void){
    int result, num1, num2;
    result = 0;
    num1 = 0x02;
    num2 = 0x03;

    // for(int i =0; i <num1; i++){
    //     result = result+num2;
    // }
   result =num1*num2;

    TRISD =0x00;
    PORTD = result;
}