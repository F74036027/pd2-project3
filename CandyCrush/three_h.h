#ifndef THREE_H_H
#define THREE_H_H
#include "destroy.h"
#include "blank.h"

class Three_H:public Destroy
{
public:
    Three_H();
    virtual void spawn(Blank * b[10][10],Blank * clicked,int mode);
    virtual void eliminate(Blank * b[10][10],Blank * clicked);
    virtual int condition(Blank *b[10][10], Blank *focus);
    virtual ~Three_H();
};

#endif // THREE_H_H
