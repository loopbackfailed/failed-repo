#include <p18f4520.h> //Include Controller specific .h

#pragma config OSC = HS     // Oscillator Selection
#pragma config WDT = OFF    // Disable Watchdog timer
#pragma config LVP = OFF    // Disable Low Voltage Programming
#pragma config PBADEN = OFF // Disable PORTB Analog inputs

void msdelay(unsigned int ms)
{
    for (int i = 0; i < ms; i++)
    {
        for (int j = 0; j < 710; j++)
        {
            ;
        }
    }
}

void main()
{
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC1 = 0;
    TRISCbits.TRISC2 = 0;
    PR2 = 0x4E;
    CCP1CON = 0x0C; // Configure CCP1CON as PWM mode.
    T2CON = 0x07;
    PORTCbits.RC0 = 1; // Turn ON the Motor
    PORTCbits.RC1 = 0;

    while (1)
    {
        CCP1CONbits.DC1B0 = 0;
        CCP1CONbits.DC1B1 = 1;
        CCPR1L = 0x3E;
        myMsDelay(1000);
        // ----------Duty Cycle 60%-----------
        CCP1CONbits.DC1B0 = 1;
        CCP1CONbits.DC1B1 = 1;
        CCPR1L = 0x2E;
        myMsDelay(1000);
        // ----------Duty Cycle 40%-----------
        CCP1CONbits.DC1B0 = 1;
        CCP1CONbits.DC1B1 = 0;
        CCPR1L = 0x1F;
        myMsDelay(1000);
        // ----------Duty Cycle 20%-----------
        CCP1CONbits.DC1B0 = 0;
        CCP1CONbits.DC1B1 = 1;
        CCPR1L = 0x0F;
        myMsDelay(1000);
    }
}
