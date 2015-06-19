#ifndef ALL_H
#define ALL_H
#include "destroy.h"
#include "blank.h"

class All:public Destroy
{
public:
    All();
    virtual void spawn(Blank * b[10][10],Blank * clicked,int mode);
    virtual void eliminate(Blank * b[10][10],Blank * clicked);
    virtual int condition(Blank *b[10][10], Blank *focus);
    virtual ~All();
};

#endif // ALL_H
