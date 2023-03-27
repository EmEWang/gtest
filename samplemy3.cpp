#include "samplemy3.h"

bool isEven3_(int a, int b, int c)
{
    int d = a+b+c;
    if (d%2 == 0)
    {
        return true;
    }

    return false;
}

int add3_(int a, int b)
{
    return a+b;
}

void throwExp(int a)
{
    if(a < 0)
        throw 1;
}