#include "BIT_math.h"
#include "STD_TYPES.H"
#include "SSG_int.h"
#include"DIO_int.h"
void SSG_vidEnable  (SSG_t * ssg)
{
    //Write high on enable pin....
    DIO_vidSetPinValue(ssg->SSG_u8_EnablePort,ssg->SSG_u8_EnablePin,DIO_HIGH);
}
void SSG_vidDisable (SSG_t * ssg);
{
    DIO_vidSetPinValue(ssg->SSG_u8_EnablePort,ssg->SSG_u8_EnablePin,DIO_LOW);
}
void SSG_vidWriteNumber (SSG_t * ssg , u8 copy_u8_number)
{
    DIO_vidSetPinValue(ssg->SSG_u8_EnablePort,ssg->SSG_u8_DataPin1,GET_BIT(copy_u8_number,0));
    DIO_vidSetPinValue(ssg->SSG_u8_EnablePort,ssg->SSG_u8_DataPin2,GET_BIT(copy_u8_number,1));
    DIO_vidSetPinValue(ssg->SSG_u8_EnablePort,ssg->SSG_u8_DataPin3,GET_BIT(copy_u8_number,2));
    DIO_vidSetPinValue(ssg->SSG_u8_EnablePort,ssg->SSG_u8_DataPin4,GET_BIT(copy_u8_number,3));
}

