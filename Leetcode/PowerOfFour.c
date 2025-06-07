#include <stdio.h>
#include <stdlib.h>

bool isPowerOfFour(int n) {
    // 1 - 4 - 16 - 64

    int v = 4;
    float a = n;
    if(a == 0)
        return false;
        
    while(a != 1.00)
    {
        if(a < 1 && a > 0)
            return false;
        if(a > -1 && a < 0)
            return false;
       a = a / v;
    }

    return true;
  
}