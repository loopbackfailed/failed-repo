// sum of array numbers on pic18f
// GROUP_A_2
#include <stdlib.h>
#include <stdio.h>
#include<p18f4550.h>
// #include <xc.h>

void main(void){
    int sum =0;
    int numbers[] = {1,2,3,4,5,6,7,8,9,10}; 
    for(int i =0; i <=9; i++){
        sum = sum + numbers[i];
    }
    TRISD =0x00;
    PORTD = sum;
}