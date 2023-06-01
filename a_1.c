// sum of hexadecimal numbers on pic18f
// GROUP_A_1
#include <stdlib.h>
#include <stdio.h>
#include<p18f4550.h>
// #include <xc.h>

void main(void){
    int a,b,sum;
    a = 0x01;
    b= 0x02;
    sum =a+b;
    
    TRISD =0x00;
    PORTD = sum;

}