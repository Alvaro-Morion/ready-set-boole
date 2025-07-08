#include "../inc/rsb.h"

unsigned int multiplier(unsigned int a, unsigned int b)
{
    unsigned int result;

    result = 0;
    while (b)
    {
        if (b & 1) //Last digit is 1 else all zeros (do nothing)
            result = adder(result, a);
        b = b >> 1; //Take the next figure
        a = a << 1; // Add a 0 in front. 
    }
    return (result);
}