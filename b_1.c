#include <p18f4520.h> //Include Controller specific .h
// Configuration bit settings

#pragma config OSC = HS //Oscillator Selection
#pragma config WDT = OFF    // Disable Watchdog timer
#pragma config LVP = OFF    // Disable Low Voltage Programming

void msdelay(unsigned int time)
{
    unsigned int i, j;
    for (i = 0; i < time; i++)
        for (j = 0; j < 710; j++)
            ; // Calibrated for a 1 ms delay in MPLAB
}

void main()
{
    TRISD = 0x00;  // To configure PORTD as output
    while (1)      // While loop for repeated operation
    {
        PORTD = 0xFF;  // Turn ON the all 
        msdelay(2000); // Delay
        PORTD = 0x00;  // Turn OFF the all 
        msdelay(2000); // Delay
    }
} 

