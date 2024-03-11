#ifndef CLCD_INT_H_
#define CLCD_INT_H_

#define NULL 0
#define CLCD_NO_ERROR 0
#define CLCD_NULL_POINTER 1

void CLCD_VidSendDta(u8);
void CLCD_VidSendCommand(u8);
void CLCD_VidIntit(void);
void CLCD_VidSendNum(u32);
u8 CLCD_U8SendString(char *copy_string);
void CLCD_VidGo(u8,u8);
void CLCD_VidClear();

#endif