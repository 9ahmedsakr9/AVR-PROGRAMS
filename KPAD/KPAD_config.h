#ifndef KPAD_CONFIG_H_
#define KPAD_CONFIG_H_


#define KPAD_COL_NUMBER 4
#define KPAD_ROW_NUMBER 4

#define KPAD_COL_PORT  DIO_PortC
#define KPAD_RAW_PORT  DIO_PortC

#define KPAD_COL_0  DIO_Pin4 
#define KPAD_COL_1  DIO_Pin5 
#define KPAD_COL_2  DIO_Pin6 
#define KPAD_COL_3  DIO_Pin7 

#define KPAD_RAW_0  DIO_Pin0 
#define KPAD_RAW_1  DIO_Pin1 
#define KPAD_RAW_2  DIO_Pin2 
#define KPAD_RAW_3  DIO_Pin3 

#define KPAD_NOTHING_PRESSED 0xff

#endif