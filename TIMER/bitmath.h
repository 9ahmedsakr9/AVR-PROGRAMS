#ifndef bitmath.h
#define bitmath.h
/****************************************************************************************************/
/*********************** Bitmath    *****************************************************************/
/** @parameters  :                           ********************************************************/
/**@return type  :                           ********************************************************/
/**@discreaption :                           ********************************************************/
/**@note  :                                                                        ******************/
/**@author:                                  ********************************************************/


#define clearbit(var,bit_num) (var&=~(1<<bit_num))
#define setbit(var,bit_num) (var|=(1<<bit_num))
#define toggle(var,bit_num) (var^=(1<<bit_num))
#define getbit(var,bit_num) ((var>>bit_num)&1)

#endif