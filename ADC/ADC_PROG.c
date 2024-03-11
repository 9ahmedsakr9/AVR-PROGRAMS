#include "bitmath.h"
#include "std_type.h"
#include "DIO_int.h"
#include "DIO_priv.h"
#include "ADC_privt.h"
#include "ADC_int.h"
#include "ADC_conf.h"
#define NULL void*0
u16 *ADC_u16_conversion_result = NULL ;
void (*vid_callback)(void) = NULL;
void ADC_Vid_Init()
{
    //setting the voltage reference either Vcc or Vf or 2.56(ADC VOLTAGE)//
    //chosing AVcc
    setbit(ADC_MUX_REG,ADC_REFS0);
    clearbit(ADC_MUX_REG,ADC_REFS1);

    //Set prescaller 
    ADC_SRA_REG &= ADC_PRESCALLER_MASK;
    ADC_SRA_REG |= ADC_PRESCALLER;

    //Enable ADC Prepheral
    setbit(ADC_SRA_REG,ADCEN);
}
u16 ADC_Vid_StartConversion(u8 Copy_channel)
{
    //set channel
    ADC_MUX_REG &= ADC_ADMUX_MASK;
    ADC_MUX_REG |= ADC_ADMUX_MASK;
    //start conversion
    setbit(ADC_SRA_REG,ADSC);
    //DELAY
    while (ADIF != 1)
    {
    }
    //CLEAR FLAG BY SETTING ADIF BIT TO 1...
    setbit(ADC_SRA_REG,ADIF);

    return ADC; 
    //ADC IS the output digital value

}


u16 ADC_Vid_Asynchrouns(u8 copy_channel22,u16 *CopyPointer_to_result,void (*copy_u8_pullback))
{
    //set channel
    ADC_MUX_REG &= ADC_ADMUX_MASK;
    ADC_MUX_REG |= ADC_ADMUX_MASK;
    //start conversion AND enable interrupt...
    setbit(ADC_SRA_REG,ADCIE);
    setbit(ADC_SRA_REG,ADSC);
    ADC_u16_conversion_result=CopyPointer_to_result;
    vid_callback=copy_u8_pullback;
}

void __vector_16(void) __attribute__((signal));

void __vector_16(void)
{
    //DISABLE INTERRUPT
    clearbit(ADC_SRA_REG,ADCIE);

    
    *ADC_u16_conversion_result=ADC;
    if(vid_callback != NULL)
    {
        vid_callback();
    }
    else{};
}