#ifndef LED_INT_H_
#define LED_INT_H_

typedef struct LED_intU8PIN
{
    u8 LED_U8PinID ;
    u8 LED_U8PortID ;
    u8 LED_U8ConecctionType;

}LED_t ;

enum {
    LED_Source =0,
    LED_sink
}LED_ConnectionType;

void LED_vidON(LED_t *copy_LED);
void LED_vidOFF(LED_t *copy_LED);
void LED_vidTOG(LED_t *copy_LED);

#endif