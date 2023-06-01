#include <p18f4520.h>

#pragma config OSC = HS     // Oscillator Selection
#pragma config WDT = OFF    // Disable Watchdog timer
#pragma config LVP = OFF    // Disable Low Voltage Programming
#pragma config PBADEN = OFF // Disable PORTB Analog inputs

#define LCD_DATA PORTD   // LCD data port to PORTD
#define ctrl PORTE       // LCD control port to PORTE
#define rs PORTEbits.RE0 // register select signal to RE0
#define rw PORTEbits.RE1 // read/write signal to RE1
#define en PORTEbits.RE2 // enable signal to RE2


void msdelay(unsigned int ms){
    for(int i=0; i < ms; i++){
        for(int j =0; j < 710 ; j++){
            ;
        }
    }
}

void LCD_command(unsigned char cmd)  {
 LCD_DATA = cmd; //Send data on LCD data bus
 rs = 0; //RS = 0 since command to LCD
 rw = 0; //RW = 0 since writing to LCD
 en = 1; //Generate High to low pulse on EN
 msdelay(15);
 en = 0;
}

void init_LCD(void) {
    LCD_command(0x38); // initialization of 16X2 LCD in 8bit mode
    msdelay(15);
    LCD_command(0x01); // clear LCD
    msdelay(15);
    LCD_command(0x0C); // cursor off
    msdelay(15);
    LCD_command(0x80); // go to first line and 0th position
    msdelay(15);
}

void LCD_data(unsigned char data)//Function to write data to the LCD
{
 LCD_DATA = data; //Send data on LCD data bus
 rs = 1; //RS = 1 since data to LCD
 rw = 0; //RW = 0 since writing to LCD
 en = 1; //Generate High to low pulse on EN
 msdelay(15);
 en = 0;
}

void LCD_write_string(static char *str) 
{
 int i = 0;
 while (str[i] != '\0') //Check for end of the string
 {
 	LCD_data(str[i]); // sending data on LCD byte by byte
 	msdelay(15);
 	i++;
 }
}

void main(void){
    char var1[] = "Welcome";
    char var2[] = "Hello World";
    ADCON1 = 0x0F; 
    TRISD = 0x00; 
    TRISE = 0x00; 
    init_LCD();
    msdelay(50);

    LCD_write_string(var1);
    msdelay(15);
    LCD_command(0xC0);
    LCD_write_string(var2);

    while(1){
        ;
    }

}