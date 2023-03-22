#include "cfunc.h"

int cadd(int a, int b)
{
    int i = a + b;
    if (i > 1)
    {
        return 1;
    }
    else if (i == 1)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}