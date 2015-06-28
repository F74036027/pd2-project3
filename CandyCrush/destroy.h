#ifndef DESTROY_H
#define DESTROY_H
#include "blank.h"

class Destroy
{
public:
    Destroy();
    virtual void spawn(Blank * b[10][10],Blank * clicked,int mode,int * score)=0;
    virtual void eliminate(Blank * b[10][10],Blank * clicked,int *score)=0;
    virtual int condition(Blank * b[10][10],Blank * focus)=0;
    virtual ~Destroy();
};

#endif // DESTROY_H
