#ifndef VERTICAL_H
#define VERTICAL_H
#include "destroy.h"
#include "blank.h"

class Vertical:public Destroy
{
public:
    Vertical();
    virtual void spawn(Blank * b[10][10],Blank * clicked,int mode,int *score);
    virtual void eliminate(Blank * b[10][10],Blank * clicked,int *score);
    virtual int condition(Blank *b[10][10], Blank *focus);
    virtual ~Vertical();
};

#endif // VERTICAL_H
