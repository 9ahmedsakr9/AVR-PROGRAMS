#ifndef CLCD_PRIV_H_
#define CLCD_PRIV_H_

//a static function is not callable by any thing ,thus stays in//
//a static function cannot be called by name from code outside its own translation unit//
static void Set_Half_Port(u8);

void Send_Enable_Pulse();

#define CLCD_4_BIT_MODE		0
#define CLCD_8_BIT_MODE		1


#endif