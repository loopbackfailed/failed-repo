// division of 8 bit numbers on pic18f
// GROUP_A_3_1
#include <stdlib.h>
#include <stdio.h>
#include<p18f4550.h>
// #include <xc.h>

void main(void){
    int result, num1, num2;
    result = 0;
    num1 = 0x06;
    num2 = 0x03;

    while(num1>=num2){
        num1=num1-num2;
        result++;
    }

    TRISD = 0x00;
    PORTD = result;
}