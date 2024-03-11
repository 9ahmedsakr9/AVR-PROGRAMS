#include "bitmath.h"
#include "std_type.h"
#include "GIE_privt.h"
#include "GIE_int.h"


void GIE_vid_EnableGIE()
{
    //we can use C or asembly for speed//
    //set bit GIE_SREG//


    //__asm("SEI"); //

    setbit(GIE_SREG,GIE_SREG_I);

}


void GIE_vid_disableGIE()
{
    //clear bit GIE_SREG//
    //__asm("CLI"); //

    clearbit(GIE_SREG,GIE_SREG_I) ;
}
