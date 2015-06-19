#ifndef ONE_COLOR_H
#define ONE_COLOR_H
#include "destroy.h"
#include "blank.h"

class One_Color:public Destroy
{
public:
    One_Color();
    virtual void spawn(Blank * b[10][10],Blank * clicked,int mode);
    virtual void eliminate(Blank * b[10][10],Blank * clicked);
    virtual int condition(Blank *b[10][10], Blank *focus);
    virtual ~One_Color();
};

#endif // ONE_COLOR_H
