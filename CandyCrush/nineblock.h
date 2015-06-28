#ifndef NINEBLOCK_H
#define NINEBLOCK_H
#include "destroy.h"
#include "blank.h"

class NineBlock:public Destroy
{
public:
    NineBlock();
    virtual void spawn(Blank * b[10][10],Blank * clicked,int mode,int *score);
    virtual void eliminate(Blank * b[10][10],Blank * clicked,int *score);
    virtual int condition(Blank *b[10][10], Blank *focus);
    virtual ~NineBlock();
};

#endif // NINEBLOCK_H
