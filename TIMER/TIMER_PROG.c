#include "std_type.h"
#include "bitmath.h"

#include "TIMER_INT.h"
#include "TIMER_PRIVT.h"
#include "TIMER_CONFG.h"

static void (*Timer0_CallBack_function)(void)=NULL;


void VID_Timer0_Int_Normal()
{
    //we select 256 prescaler... subject to change in future
    //Note....MASK IS USED ...to prevent the register from CHANGING VALUE , and to controll prescale

    TIMER_REGISTER_TCCR0 &= PrescallMask;
    TIMER_REGISTER_TCNT0 |= Timer0_Prescaler;


    //adding a pre-value....can be changed by TIMER_CONFG.h...//
    TIMER_REGISTER_TCNT0  = Timer0_preload;

    //for normal start settings//
    clearbit(TIMER_REGISTER_TCCR0,TIMER_TCCR0_WGM00);
    clearbit(TIMER_REGISTER_TCCR0,TIMER_TCCR0_WGM01);

    //overflow interrupt enable//
    setbit(TIMER_REGISTER_TIMSK,TIMER_TIMSK_TOIE0);
}

void VID_Timer0_PreloadValue(u8 copy_preload)
{
    TIMER_REGISTER_TCNT0 =copy_preload;
}

//Call back function is used ... with ISR //
//we are going to use a function pointer to specify which function should be executed when the interrupt fires. //
//If we have not assigned an interrupt, that is the function pointer is assign NULL, then we do nothing. //
//If the function pointer is assigned, then we execute the function.//
//The comment is From BENINGO.COM //


u8  Timer0_u8SetCallBack(void(*Copy_CallBack_function)(void))
{
    u8 *Local_State=1;
    if (Timer0_CallBack_function != NULL)
    {
        Timer0_CallBack_function=Copy_CallBack_function;
    }
    else
    {
        Local_State=NULL;
    }
    return Local_State;
}

