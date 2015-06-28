#ifndef SPAWN5_H
#define SPAWN5_H
#include "blank.h"
#include "destroy.h"

class Spawn5:public Destroy
{
public:
    Spawn5();
    virtual void spawn(Blank * b[10][10],Blank * clicked,int mode,int *score);
    virtual void eliminate(Blank * b[10][10],Blank * clicked,int *score);
    virtual int condition(Blank * b[10][10],Blank * focus);
    virtual ~Spawn5();
};

#endif // SPAWN5_H
