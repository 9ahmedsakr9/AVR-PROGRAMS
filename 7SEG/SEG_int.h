#ifndef SEG_INT_H_
#define SEG_INT_H_

typedef struct 
{
    u8 SEG_u8_EnalePin;
    u8 SEG_u8_EnablePort;
    u8 SEG_u8_DataPin1;
    u8 SEG_u8_DataPin2;
    u8 SEG_u8_DataPin3;
    u8 SEG_u8_DataPin4;
    u8 SEG_u8_DataPort;
}SEG_t;

void SEG_vidEnable(SEG_t * SEG);
void SEG_vidDisable(SEG_t * SEG);
void SEG_vidDisplay(SEG_t * SEG,u8 copy_u8_number);

#endif