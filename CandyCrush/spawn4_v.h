#ifndef SPAWN4_V_H
#define SPAWN4_V_H
#include "destroy.h"
#include "blank.h"

class Spawn4_V:public Destroy
{
public:
    Spawn4_V();
    virtual void spawn(Blank * b[10][10],Blank * clicked,int mode);
    virtual void eliminate(Blank * b[10][10],Blank * clicked);
    virtual int condition(Blank *b[10][10], Blank *focus);
    virtual ~Spawn4_V();
};

#endif // SPAWN4_V_H
