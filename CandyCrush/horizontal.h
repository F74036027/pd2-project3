#ifndef HORIZONTAL_H
#define HORIZONTAL_H
#include "destroy.h"
#include "blank.h"

class Horizontal:public Destroy
{
public:
    Horizontal();
    virtual void spawn(Blank * b[10][10],Blank * clicked,int mode);
    virtual void eliminate(Blank * b[10][10],Blank * clicked);
    virtual int condition(Blank *b[10][10], Blank *focus);
    virtual ~Horizontal();
};

#endif // HORIZONTAL_H
