/***************************************************By Ahmed Sakr*************************************************************/
/********************************DIO header file in which fanctions will be called********************************************/
/************************************************** Version : 1.1.1***********************************************************/
#if !defined DIO_INT_H_
#define DIO_INT_H_

/** defining the ports and pins*/

#define DIO_PortA 0
#define DIO_PortB 1
#define DIO_PortC 2
#define DIO_PortD 3

#define DIO_Pin0 0
#define DIO_Pin1 1
#define DIO_Pin2 2
#define DIO_Pin3 3
#define DIO_Pin4 4
#define DIO_Pin5 5
#define DIO_Pin6 6
#define DIO_Pin7 7


/** dfining direction (1 for output .....0 for input)*/

#define DIO_Output 0xff
#define DIO_Input 0x00

#define DIO_HIGH 0xff
#define DIO_LOW 0x00

/** Set port/pin value and direction .....*/
void DIO_VidSetPortDirection(u8 ,u8  );
void DIO_VidSetPortValue(u8 ,u8 );
void DIO_VidSetPinDirection(u8 ,u8,u8);
void DIO_VidSet5PinValue(u8,u8, u8);


/***Get a port/pin vale ..........*/
u8 DIO_VidGetPortValue(u8);
u8 DIO_VidGetPinValue(u8 ,u8);

/**Toggle a port/Pin ........*/
void DIO_vidTogglePort(u8);
void DIO_vidTogglePin(u8,u8);
#endif