#ifndef TIMER_PRIVT_H_
#define TIMER_PRIVT_H_  


//Registers for timer control---->TCCR0 , TIMSK , TIFR 
//TIMER/COUNTER CONTROL REGISTER , TIMER/COUNTER INTERRUPT MASK REGISTER
//TIMER/COUNTER INTERRUPT FLAG REGISTER ...check ATMEGA32 datsheet pg 82.. 

#define TIMER_REGISTER_TCCR0 *((volatile u8*)0x53)
#define TIMER_REGISTER_TIFR  *((volatile u8*)0x58)
#define TIMER_REGISTER_TIMSK *((volatile u8*)0x59)
#define TIMER_REGISTER_TCNT0 *((volatile u8*)0x52)



//define important bits

#define TIMER_TCCR0_CS00  0
#define TIMER_TCCR0_CS01  1
#define TIMER_TCCR0_CS02  2
#define TIMER_TCCR0_WGM01 3
#define TIMER_TCCR0_COM00 4
#define TIMER_TCCR0_COM01 5
#define TIMER_TCCR0_WGM00 6
#define TIMER_TCCR0_FOC0  7


#define TIMER_TIMSK_TOIE0 0
#define TIMER_TIMSK_OCIE0 1

#define TIMER_TIFR_TOV0 0
#define TIMER_TIFR_OCF0 1

//prescall Mask//

#define PrescallMask    0xb11111000

#endif