#include"add.h"

Add::Add(int a, int b)
{
    this->a=a;
    this->b=b;  
}

int Add::add()
{
    int c;
    c=a+b;
    return c;
}
