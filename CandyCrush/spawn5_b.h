#ifndef SPAWN5_B_H
#define SPAWN5_B_H
#include "destroy.h"
#include "blank.h"

class Spawn5_B:public Destroy
{
public:
    Spawn5_B();
    virtual void spawn(Blank * b[10][10],Blank * clicked,int mode);
    virtual void eliminate(Blank * b[10][10],Blank * clicked);
    virtual int condition(Blank *b[10][10], Blank *focus);
    virtual ~Spawn5_B();
};

#endif // SPAWN5_B_H
