#include<stdlib.h>
#include"std_type.h"
#include"DIO_int.h"
#include"DIO_priv.h"
#include"bitmath.h"

void DIO_VidSetPortDirection(u8 u8_CopyPortID,u8 u8_CopyPortDirection )
{
    if (u8_CopyPortDirection >=0x00 && u8_CopyPortDirection <=0xff)
    {
    
    switch (u8_CopyPortID)
    {
    case (DIO_PortA):
        DIO_DDRA_REG =u8_CopyPortDirection;
        break;
     case (DIO_PortB):
        DIO_DDRB_REG =u8_CopyPortDirection;
        break;
     case (DIO_PortC):
        DIO_DDRC_REG =u8_CopyPortDirection;
        break;
     case (DIO_PortD):
        DIO_DDRD_REG =u8_CopyPortDirection;
        break;
    
    default:
        #warning("wrong port name/ID");
        break;
    }
    }
    else {
        #warning("wrong input direction value");
    }
}



void DIO_VidSetPortValue(u8 u8_CopyPortID ,u8 u8_CopyPortValue )
{
    if (u8_CopyPortValue >=0x00 && u8_CopyPortValue <=0xff)
    {
        switch (u8_CopyPortID)
        {
        case DIO_PortA:
            DIO_PORTA_REG=u8_CopyPortValue;
            break;
        case DIO_PortB:
            DIO_PORTB_REG=u8_CopyPortValue;
            break;
        case DIO_PortC:
            DIO_PORTC_REG=u8_CopyPortValue;
            break;
        case DIO_PortD:
            DIO_PORTD_REG=u8_CopyPortValue;
            break;
        
        default:
            #warning ("Wrong Port name/ID");
            break;
        }
    }
    else
    {
        #warning("Wrong port value....... must be 0x00 or 0xff");
    }
    
    
}



void DIO_VidSetPintDirection(u8 u8_CopyPortID ,u8 u8_CopyPinID,u8 u8_CopyDirection)
{
    if (u8_CopyPinID < 8 && u8_CopyPinID >=0)
    {
        if (u8_CopyDirection == DIO_Output)
        {
            switch (u8_CopyPortID)
            {
            case (DIO_PortA):
                setbit(DIO_DDRA_REG,u8_CopyPinID);
                break;
             case (DIO_PortB):
                setbit(DIO_DDRB_REG,u8_CopyPinID);
                break;
             case (DIO_PortC):
                setbit(DIO_DDRC_REG,u8_CopyPinID);
                break;
             case (DIO_PortD):
                setbit(DIO_DDRD_REG,u8_CopyPinID);
                break;
            default:
                #warning("wrong port name ....");
                break;
            }
        }
        else if (u8_CopyDirection == DIO_Input)
        {
             switch (u8_CopyPortID)
            {
            case (DIO_PortA):
                clearbit(DIO_DDRA_REG,u8_CopyPinID);
                break;
             case (DIO_PortB):
                clearbit(DIO_DDRB_REG,u8_CopyPinID);
                break;
             case (DIO_PortC):
                clearbit(DIO_DDRC_REG,u8_CopyPinID);
                break;
             case (DIO_PortD):
                clearbit(DIO_DDRD_REG,u8_CopyPinID);
                break;
            default:
                #warning("wrong port name ....");
                break;
            } 
        }
        
    }
    else 
    {
        #warning ("wrong Pin value/location ... only from 0 to 7....");
    }
    
}



void DIO_VidSet5PinValue(u8 u8_CopyPortID,u8 u8_CopyPinID,u8 u8_CopyPinValue)
{
    if (u8_CopyPinID < 8  &&  u8_CopyPinID >=0)
    {
    if (u8_CopyPinValue == DIO_HIGH )
    {
            switch (u8_CopyPortID)
            {
            case (DIO_PortA):
                setbit(DIO_PORTA_REG,u8_CopyPinID);
                break;
             case (DIO_PortB):
                setbit(DIO_PORTB_REG,u8_CopyPinID);
                break;
             case (DIO_PortC):
                setbit(DIO_PORTC_REG,u8_CopyPinID);
                break;
             case (DIO_PortD):
                setbit(DIO_PORTD_REG,u8_CopyPinID);
                break;
            default:
                #warning("wrong port name ....");
                break;
            }
        }
    else if (u8_CopyPinValue == DIO_LOW)
    {
         switch (u8_CopyPortID)
            {
            case (DIO_PortA):
                clearbit(DIO_PORTA_REG,u8_CopyPinID);
                break;
             case (DIO_PortB):
                clearbit(DIO_PORTB_REG,u8_CopyPinID);
                break;
             case (DIO_PortC):
                clearbit(DIO_PORTC_REG,u8_CopyPinID);
                break;
             case (DIO_PortD):
                clearbit(DIO_PORTD_REG,u8_CopyPinID);
                break;
            default:
                #warning("wrong port name ....");
                break;
            } 
        }
}
else 
{
    #warning ("wrong Pin ID ...from 0 to 7 only!!");
}
} 



u8 DIO_VidGetPortValue(u8 u8_CopyPortID)
{
    u8 u8_CopyPortValue=0;
    switch (u8_CopyPortID)
    {
    case (DIO_PortA):
       u8_CopyPortValue=DIO_PORTA_REG;
        break;
    case (DIO_PortB):
       u8_CopyPortValue=DIO_PORTB_REG;
        break;
    case (DIO_PortC):
        u8_CopyPortValue=DIO_PORTC_REG;
        break;
    case (DIO_PortD):
        u8_CopyPortValue=DIO_PORTD_REG;
        break;
    default:
        #warning ("wrong Port name");
        break;
    }    
return u8_CopyPortValue;
}


u8 DIO_VidGetPinValue(u8 u8_CopyPortID,u8 u8_CopyPinID)
{
    u8 u8_CopyPinValue=0;
    switch (u8_CopyPortID)
        {
        case (DIO_PortA):
        u8_CopyPinValue =getbit(DIO_PINA_REG,u8_CopyPinID);
            break;
        case (DIO_PortB):
        u8_CopyPinValue = getbit(DIO_PINB_REG,u8_CopyPinID);
            break;
        case (DIO_PortC):
        u8_CopyPinValue = getbit(DIO_PINC_REG,u8_CopyPinID);
            break;
        case (DIO_PortD):
        u8_CopyPinValue = getbit(DIO_PIND_REG,u8_CopyPinID);
            break;
        default:
            #warning("wrong port name ....");
            break;
        }
    return u8_CopyPinValue; 
}


void DIO_vidTogglePort(u8 u8_copyPortID  )
{
	switch(u8_copyPortID)
			{

			case (DIO_PortA) : DIO_PORTA_REG ^= 0xFF ; break ;
			case (DIO_PortB) : DIO_PORTB_REG ^= 0xFF ; break ;
			case (DIO_PortC) : DIO_PORTC_REG ^= 0xFF ; break ;
			case (DIO_PortD) : DIO_PORTD_REG ^= 0xFF ; break ;
			default : break ;
			}

}



void DIO_vidTogglePin(u8 u8_CopyPortID,u8 u8_CopyPinID)
{
    if (u8_CopyPinID  < 8  && u8_CopyPinID >=0)
    {
        switch (u8_CopyPortID)
        {
        case (DIO_PortA):
            toggle(DIO_PINA_REG,u8_CopyPinID);
            break;
         case (DIO_PortB):
            toggle(DIO_PINB_REG,u8_CopyPinID);
            break;
         case (DIO_PortC):
            toggle(DIO_PINC_REG,u8_CopyPinID);
            break;
         case (DIO_PortD):
            toggle(DIO_PIND_REG,u8_CopyPinID);
            break;
        default:
            #warning("wrong port name ......");
            break;
        }
    }
    else
    {
        #warning("wrong Pin ID");
    }
}
