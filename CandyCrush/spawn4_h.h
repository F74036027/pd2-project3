#ifndef SPAWN4_H_H
#define SPAWN4_H_H
#include "destroy.h"
#include "blank.h"

class Spawn4_H:public Destroy
{
public:
    Spawn4_H();
    virtual void spawn(Blank * b[10][10],Blank * clicked,int mode);
    virtual void eliminate(Blank * b[10][10],Blank * clicked);
    virtual int condition(Blank *b[10][10], Blank *focus);
    virtual ~Spawn4_H();
};

#endif // SPAWN4_H_H
