#include "bitmath.h"
#include "std_type.h"
#include "UART_int.h"
#include "UART_cong.h"
#include "UART_privt.h"


void USART_vid_init()
{
    //set baud rate 103 FOR 9600
    //send or recieve mode?
    //send 5,6,7,8,9 bits?
    //odd or even parity??
    //number of stop bits ...1 or 2
    USART_UBRRL_REG=103;
    //select UCSRC REG (adress ox40)
    setbit(USART_UCSRC_REG,USART_UCSRC_URSEL); 
    setbit(USART_UCSRC_REG,USART_UCSRC_UCSZ0); 
    setbit(USART_UCSRC_REG,USART_UCSRC_UCSZ1); 
    setbit(USART_UCSRC_REG,USART_UCSRC_URSEL); 

    //selecting send and transmit mode
    setbit(USART_UCSRB_REG,USART_UCSRB_RXEN);
    setbit(USART_UCSRB_REG,USART_UCSRB_TXEN);
}

void USART_vid_send(u16 copy_data_u16)
{
    //check on UDRE flag
    while (getbit(USART_UCSRA_REG,USART_UCSRA_UDRE) !=1)
    {
        //do nothing
    }
    USART_UDR_REG = (u8) copy_data_u16;
    //wait....on TX flag
    while (getbit(USART_UCSRA_REG,USART_UCSRA_TXC) !=1)
    {
        /* nothing */
    }
    
}


u16 USART_U16_Recieve()
{
    //check RX flag
    while (getbit(USART_UCSRA_REG,USART_UCSRA_RXC) !=1)
    {
        /* nothing */
    }
    u16 copy_data_local =USART_UDR_REG;
    

    return copy_data_local;
}