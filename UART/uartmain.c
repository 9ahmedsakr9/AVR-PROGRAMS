#include "bitmath.h"
#include "std_type.h"
#include "DIO_int.h"
#include "UART_int.h"




void main ()
{
    DIO_VidSetPinDirection(DIO_PortD,DIO_Pin1,DIO_Output);
    DIO_VidSetPinDirection(DIO_PortD,DIO_Pin0,DIO_Input);
    USART_vid_init();
    USART_vid_send('a');


    while (1)
    {
        
    }
    
}