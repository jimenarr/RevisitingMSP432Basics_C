#include <msp430.h>

int main(void)
{
    volatile unsigned int i;
    WDTCTL = WDTPW + WDTHOLD;     // Stop watchdog timer

    // |= (BIT) HIGH ON 1  
    // &= ~(BIT) LOW OFF 0 
    // 1 = pullup
    // 0 = pulldown
    // P1OUT |= BIT; //LED ON
    // P1OUT &= ~(BIT); //LED OFF
    
    //OUTPUT P1.6 0x40
    P1DIR |= 0x40;  //set as outptup
    P1OUT &= ~(0x40); //set output to off

    //INPUT P1.3 0x08
    P1DIR &= ~(0x08);  //set input
    P1REN |= 0x08;  //enable pull resistor 
    P1OUT |= 0x08; //set resistor to pull up HIGH

    while(1)
    {
      //if P1IN is low then turn on the light else LED is off
      if ( !(P1IN & 0x08) ){
        //turn LED on
        P1OUT |= 0x40;
        
      } else {
        //LED is off
        P1OUT &= ~(0x40); 
      }
    }

}



