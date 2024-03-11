#include "std_type.h"
#include "bitmath.h"
#include "DIO_int.h"
#include "KPAD_config.h"
#include "KPAD_int.h"

void KPAD_vidGEtKeyPressed(u8 *copy_column,u8 *copy_raw)
{
    u8 local_raw_index=0;
    u8 local_column_index=0;
    u8 local_pin_state;
    *copy_column=KPAD_NOTHING_PRESSED;
    *copy_raw=KPAD_NOTHING_PRESSED;
    u8 local_column_Array{KPAD_COL_NUMBER}={KPAD_COL_0,KPAD_COL_1,KPAD_COL_2,KPAD_COL_3}
}