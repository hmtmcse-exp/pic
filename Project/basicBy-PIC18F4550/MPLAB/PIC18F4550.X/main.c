/*
 * File:   main.c
 * Author: Touhid Mia
 *
 * Created on 4 September 2014, 9:37 PM
 */

#include <xc.h>

#define _XTAL_FREQ 1000000 //This is the speed your controller is running at

// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG1L
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = EC_EC     // Oscillator Selection bits (EC oscillator, CLKO function on RA6 (EC))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = ON         // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = ON         // Watchdog Timer Enable bit (WDT enabled)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = ON      // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = OFF      // MCLR Pin Enable bit (RE3 input pin enabled; MCLR pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
#pragma config ICPRT = OFF      // Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit (ICPORT disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)


int i = 0;
void Delay1Second(int interval);
void yallowLight(void);
void roadOne(void);
void roadTwo(void);
void oneToNine(void);
void one(void);
void two(void);
void three(void);
void four(void);
void five(void);
void six(void);
void seven(void);
void eight(void);
void nine(void);
void zero(void);

void main(int argc, char** argv) {

    TRISBbits.RB0 = 0;
    TRISBbits.RB1 = 0;
    TRISBbits.RB2 = 0;

    TRISBbits.RB3 = 0;
    TRISBbits.RB4 = 0;
    TRISBbits.RB5 = 0;
    TRISBbits.RB6 = 0;

    TRISAbits.RA0 = 1;
    TRISAbits.RA1 = 0;

    while(1) //infinite loop
    {
        yallowLight();
        roadOne();
        yallowLight();
        roadTwo();
    }
}


void yallowLight(){
        zero();
        LATB2 = 1; //Yallow Light ON
        Delay1Second(300);
        LATB2 = 0; //Yallow Light OFF
}

void roadOne(){
   LATB0 = 1;
   oneToNine();
   LATB0 = 0;
}

void roadTwo(){
   LATB1 = 1;
   oneToNine();
   LATB1 = 0;
}


void oneToNine(){
one();
Delay1Second(100);
two();
Delay1Second(100);
three();
Delay1Second(100);
four();
Delay1Second(100);
five();
Delay1Second(100);
six();
Delay1Second(100);
seven();
Delay1Second(100);
eight();
Delay1Second(100);
nine();
Delay1Second(100);
}

void one(){
LATB3 = 1;
LATB4 = 0;
LATB5 = 0;
LATB6 = 0;
}

void two(){
LATB3 = 0;
LATB4 = 1;
LATB5 = 0;
LATB6 = 0;
}

void three(){
LATB3 = 1;
LATB4 = 1;
LATB5 = 0;
LATB6 = 0;
}

void four(){
LATB3 = 0;
LATB4 = 0;
LATB5 = 1;
LATB6 = 0;
}

void five(){
LATB3 = 1;
LATB4 = 0;
LATB5 = 1;
LATB6 = 0;
}

void six(){
LATB3 = 0;
LATB4 = 1;
LATB5 = 1;
LATB6 = 0;
}

void seven(){
LATB3 = 1;
LATB4 = 1;
LATB5 = 1;
LATB6 = 0;
}

void eight(){
LATB3 = 0;
LATB4 = 0;
LATB5 = 0;
LATB6 = 1;
}

void nine(){
LATB3 = 1;
LATB4 = 0;
LATB5 = 0;
LATB6 = 1;
}

void zero(){
LATB3 = 0;
LATB4 = 0;
LATB5 = 0;
LATB6 = 0;
}


void Delay1Second(int interval)
{
    for(i=0;i<interval;i++)
        __delay_ms(10);
}


