
#include "samplemy2.h"


int Foo(int a,int b) {
    if(0 == a||0 == b) {
        throw "don't do that";
    }

    int c = a % b;
    if (0 == c) {
        return b;
    }
    return Foo(b, c);
}

int Action(int a, int b)
{
    if (a > b)
    {
        return 1;
    }
    else if (a == b)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int Device(int a, int b)
{
    int i = a/b;
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

int Add(int a, int b)
{
    int i = a+b;
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



int Calc::add(int a, int b) {
    return a + b;
};
