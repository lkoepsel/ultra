#include "unolib.h"
#include "pinMode.h"
#include "digitalWrite.h"
#include "delay.h"
 
int main(void)
{
    /* set LED to output*/
    pinMode(4, OUTPUT);

    while(1) 
    {
        /* toggle led on and off */
        digitalWrite(4, HIGH);
        delay(200);
        digitalWrite(4, LOW);
        delay(200);
    }
    return(0); 
}
