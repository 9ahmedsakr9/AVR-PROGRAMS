#ifndef UART_PRIVT_H_
#define UART_PRIVT_H_

#define USART_UCSRA_REG *((volatile u8*) 0x2b)
#define USART_UCSRB_REG *((volatile u8*) 0x2a)
#define USART_UCSRC_REG *((volatile u8*) 0x40)
#define USART_UDR_REG   *((volatile u8*) 0x2c)
#define USART_UBRRL_REG *((volatile u8*) 0x29)
#define USART_UBBRH_REG *((volatile u8*) 0x40)


//Important (ALL) bits of UCSRA regitser
#define USART_UCSRA_RXC  7
#define USART_UCSRA_TXC  6
#define USART_UCSRA_UDRE 5
#define USART_UCSRA_FE   4
#define USART_UCSRA_DOR  3
#define USART_UCSRA_PE   2
#define USART_UCSRA_U2X  1
#define USART_UCSRA_MPCM 0

//Bits of UCSRB Register

#define USART_UCSRB_RXCIE 7
#define USART_UCSRB_TXCIE 6
#define USART_UCSRB_UDRIE 5
#define USART_UCSRB_RXEN  4
#define USART_UCSRB_TXEN  3
#define USART_UCSRB_UCSZ2 2
#define USART_UCSRB_RXB8  1
#define USART_UCSRB_TXB8  0

//BITS OF UCSRC REGISTER

#define USART_UCSRC_URSEL   7
#define USART_UCSRC_UMSEL   6
#define USART_UCSRC_UPM0    5
#define USART_UCSRC_UPM1    4
#define USART_UCSRC_USBS    3
#define USART_UCSRC_UCSZ0   2
#define USART_UCSRC_UCSZ1   1
#define USART_UCSRC_MPCM    0


//BAUD RATE = 103 mainly 


#endif