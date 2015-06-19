#ifndef THREE_V_H
#define THREE_V_H
#include "destroy.h"
#include "blank.h"

class Three_V:public Destroy
{
public:
    Three_V();
    virtual void spawn(Blank * b[10][10],Blank * clicked,int mode);
    virtual void eliminate(Blank * b[10][10],Blank * clicked);
    virtual int condition(Blank *b[10][10], Blank *focus);
    virtual ~Three_V();
};

#endif // THREE_V_H
