#include"delay.h"
#include"std_type.h"
#include"bitmath.h"
#include"DIO_int.h"
#include"CLCD_privt.h"
#include"CLCD_confg.h"
#include"CLCD_int.h"


static void Set_Half_Port(u8 copyu8data)
{
    DIO_VidSet5PinValue(CLCD_u8_DATA_PORT,CLCD_u8_DATA_PIN_0,getbit(copyu8data,0));
    DIO_VidSet5PinValue(CLCD_u8_DATA_PORT,CLCD_u8_DATA_PIN_1,getbit(copyu8data,1));
    DIO_VidSet5PinValue(CLCD_u8_DATA_PORT,CLCD_u8_DATA_PIN_2,getbit(copyu8data,2));
    DIO_VidSet5PinValue(CLCD_u8_DATA_PORT,CLCD_u8_DATA_PIN_3,getbit(copyu8data,3));
}

void Send_Enable_Pulse()
{
    DIO_VidSet5PinValue(CLCD_u8_E_PIN,DIO_HIGH);
    _delay_ms(2);
    DIO_VidSet5PinValue(CLCD_u8_E_PIN,DIO_LOW);
}
void CLCD_vidSendData(u8 copyu8data)
{
    //WE first make RS pin to high and then R/W pin to low to enable writing....//
    DIO_VidSet5PinValue(CLCD_u8_CTRL_PORT,CLCD_u8_RS_PIN,DIO_HIGH);
    DIO_VidSet5PinValue(CLCD_u8_CTRL_PORT,CLCD_u8_RW_PIN,DIO_LOW);
    #if CLCD_MODE == CLCD_8_BIT_MODE
    DIO_VidSetPortValue(CLCD_u8_DATA_PORT,copyu8data);
    Send_Enable_Pulse();
    //data then enable pulse//
    #elif CLCD_MODE === CLCD_4_BIT_MODE
    /*Set_Half_Port(copyu8data>>4);
    Send_Enable_Pulse();
    Set_Half_Port(copyu8data);
    Send_Enable_Pulse();*/
    #endif
}
void CLCD_vidSendCommand(u8 copyu8data)
{
    DIO_VidSet5PinValue(CLCD_u8_CTRL_PORT,CLCD_u8_RS_PIN,DIO_LOW);
    DIO_VidSet5PinValue(CLCD_u8_CTRL_PORT,CLCD_u8_RW_PIN,DIO_LOW);
    #if CLCD_MODE == CLCD_8_BIT_MODE 
    DIO_VidSetPortValue(CLCD_u8_DATA_PORT,copyu8data);
    Send_Enable_Pulse();
    #elif CLCD_MODE == CLCD_4_BIT_MODE
    /*Set_Half_Port(copyu8data>>4);
    Send_Enable_Pulse();
    Set_Half_Port(copyu8data);
    Send_Enable_Pulse();*/
    #endif
}
void CLCD_int()
{
    _delay_ms(40);
    #if CLCD_MODE == CLCD_8_BIT_MODE
    CLCD_VidSendCommand(0b00111000);
    #elif CLCD_MODE == CLCD_4_BIT_MODE
    Set_Half_Port(0b0010);
    Send_Enable_Pulse();
    Set_Half_Port(0b0010);
    Send_Enable_Pulse();
    Set_Half_Port(0b1000);
    Send_Enable_Pulse();
    #endif
    //deisplay and cursior settings (see data sheet)//
    CLCD_VidSendCommand(0b00001100);

    //clearing dispaly//

    CLCD_VidSendCommand(1);
}

u8 CLCD_U8SendString(char *copyStringPointer)
{
    //the string is an array ... we use another variable for array memebers//
    //an error may be returned via ErroStae variable
    u8 Local_u8_ErrorState = CLCD_NO_ERROR ;
	u8 Local_u8_iterator = 0 ;
    //Now ...if pointer points to null...
    if (copyStringPointer == NULL)
    {
        Local_u8_ErrorState = CLCD_NULL_POINTER;
    }
    else 
    {
        while (copyStringPointer[Local_u8_iterator]!='\0')
        {
            CLCD_vidSendData(copyStringPointer(Local_u8_iterator));
            Local_u8_iterator++;
        }
        
    }
    
    return Local_u8_ErrorState;
}

void CLCD_vidSendNumber(u32 CopyNumber)
{
    u32 Local_reversed_number =0;
    while (CopyNumber != 0)
    {
        Local_reversed_number=(Local_reversed_number*10) + (CopyNumber%10);
        CopyNumber /=10;
    }
    //Now send data//
    while (Local_reversed_number !=0)
    {
        //from data sheet ... the upper bits will add 48 in binary ...thus we added '0'//
        CLCD_vidSendData((Local_reversed_number%10)+'0');
        Local_reversed_number /=10;
    }
    
}

void CLCD_vidGoToXY(u8 Copy_u8X	,u8 Copy_u8Y)
{
    u8 local_u8_address = 0;
	if (Copy_u8Y == 1)
	{
		local_u8_address = Copy_u8X + 0x40 ;
	}
	else if (Copy_u8Y == 0)
	{
		local_u8_address = Copy_u8X ;
	}
	else
	{

	}
	SET_BIT(local_u8_address , 7);

	CLCD_vidSendCommand(local_u8_address);
}

void CLCD_VidClear()
{
    CLCD_VidSendCommand(1);
}
