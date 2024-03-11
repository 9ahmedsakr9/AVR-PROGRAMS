#ifndef TIMER_INT_H_
#define TIMER_INT_H_


void VID_Timer0_Int_Normal();

void VID_Timer0_PreloadValue(u8 copy_preload);

u8  Timer0_u8SetCallBack(void(*Copy_CallBack_function)(void));

#define NULL ((void *)0)


#endif