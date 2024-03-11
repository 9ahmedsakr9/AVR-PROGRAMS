#ifndef CLCD_CFG_H_
#define CLCD_CFG_H_


#define CLCD_u8_DATA_PORT   DIO_PortA 
#define CLCD_u8_CTRL_PORT   DIO_PortB 

#define CLCD_u8_RS_PIN      DIO_Pin1
#define CLCD_u8_RW_PIN      DIO_Pin2
#define CLCD_u8_E_PIN       DIO_Pin3

#define CLCD_MODE   CLCD_8_BIT_MODE
#if CLCD_MODE == CLCD_4_BIT_MODE

#define CLCD_u8_DATA_PIN_0		DIO_Pin4
#define CLCD_u8_DATA_PIN_1		DIO_Pin5
#define CLCD_u8_DATA_PIN_2		DIO_Pin6
#define CLCD_u8_DATA_PIN_3		DIO_Pin7


#endif

#endif