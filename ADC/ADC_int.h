#ifndef ADC_INT_H
#define ADC_INT_H

void ADC_Vid_Init();
//takes u8 as an input channel//
u16 ADC_Vid_StartConversion(u8);


//Asynchrouns conversion

u16 ADC_Vid_Asynchrouns(u8,u8*,void (*copy_u8_pullback));


#endif