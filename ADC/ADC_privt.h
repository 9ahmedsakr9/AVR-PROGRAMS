#ifndef ADC_PRIVT_H
#define ADC_PRIVT_H

#define ADC_MUX_REG *((volatile u8 *)0x27)
#define ADC_SRA_REG *((volatile u8 *)0x26)


#define ADC_ADCH_REG *((volatile u8 *)0x25)
#define ADC_ADCL_REG *((volatile u8 *)0x24)
#define ADC *((volatile u16 *)0x25)

//ADC SRA REGISTER PINS
#define ADCEN   7
#define ADSC   6
#define ADATE   5
#define ADIF  4
#define ADCIE   3
#define ADPS2  2
#define ADPS1  1
#define ADPS0  0


//ADC MUX REGISTER PINS
#define ADC_REFS1 7
#define ADC_REFS0 6


#define ADC_PRESCALLER_MASK  0xf8
//1111 1000 As we need 3 bits//


#define ADC_ADMUX_MASK 0xE0




#endif