#include <avr/delay.h>
#include "C:/Users/LAPTOP WORLD/Documents/CMD PROGRAMS/AVR PROGRAMS/7SEG/DIO_int.h" 
#include "C:/Users/LAPTOP WORLD/Documents/CMD PROGRAMS/AVR PROGRAMS/7SEG/bitmath.h" 
#include "C:/Users/LAPTOP WORLD/Documents/CMD PROGRAMS/AVR PROGRAMS/7SEG/SEG_int.h" 
#include "C:/Users/LAPTOP WORLD/Documents/CMD PROGRAMS/AVR PROGRAMS/7SEG/std_type.h" 
#include "C:/Users/LAPTOP WORLD/Documents/CMD PROGRAMS/AVR PROGRAMS/7SEG/DIO_priv.h" 
int main(void)
{
	DIO_VidSetPortDirection(DIO_DDRA_REG,DIO_Output);
	DIO_VidSetPinDirection(DIO_PortB , DIO_Pin1 , DIO_Output) ;
	DIO_VidSetPinDirection(DIO_PortB , DIO_Pin2 , DIO_Output) ;
	SEG_t SSG1;
	SEG_t SSG2;
	SSG1.SEG_u8_EnalePin=DIO_Pin1;
	SSG2.SEG_u8_EnalePin=DIO_Pin2;
	SSG1.SEG_u8_EnablePort=DIO_DDRB_REG;
	SSG2.SEG_u8_EnablePort=DIO_DDRB_REG;
	SSG1.SEG_u8_DataPort=DIO_PORTA_REG;
    while(1)
    {
       
		SEG_vidDisplay(SSG1,9);
    }
}
