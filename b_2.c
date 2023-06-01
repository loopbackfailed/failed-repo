#include <p18f4520.h>

#pragma config OSC = HS 
#pragma config WDT = OFF 
#pragma config LVP = OFF
#pragma config PBADEN = OFF 

void msdelay(unsigned int ms){
    for(int i=0; i < ms; i++){
        for(int j =0; j < 1000 ; j++){
            ;
        }
    }
}

void main(){
    INTCON2bits.RBPU=0;   		//To Activate the internal pull on PORTB
    ADCON1 =0x0F;

    TRISA = 0x00;			
	TRISB = 0x00;				
	TRISC = 0x00;				
	TRISD = 0x00;				
	TRISE = 0x00;	
    while(1){
        PORTA =0XAA; // 10101010
        PORTB = 0xAA;
		PORTC = 0xAA;
		PORTD = 0xAA;
		PORTE = 0xAA;

        msdelay(200);

        PORTA = 0x55; //01010101
		PORTB = 0x55;
		PORTC = 0x55;
		PORTD = 0x55;
		PORTE = 0x55;

    }

}