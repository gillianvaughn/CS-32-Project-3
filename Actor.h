#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
class StudentWorld;
// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class Actor: public GraphObject
{
public:
    //simple constructor
    Actor(int imageID, double startX, double startY, int dir=0, double size=1.0, int depth=0, int state =1);
    virtual void doSomething() =0;
    //virtual void moveTo(double x, double y);//????
    
protected:
    const int DEAD =0;
    const int ALIVE =1;
    void setState(int state);
    int getState() const;
    
private:
    int actorState;
    
};
class Wall: public Actor
{
public:
    Wall(double level_x, double level_y);
    virtual void doSomething();
private:
    //idk
};
class Penelope: public Actor
{
public:
    Penelope(double level_x, double level_y);
    virtual void doSomething();
    StudentWorld* getWorld();
    void setWorld(StudentWorld* world);
private:
    
    StudentWorld* world;
    void moveX(int movement);//to check and see if it is okay to move in the X direction
    void moveY(int movement); //to check and see if it is okay to move in the Y direction 
};
#endif // ACTOR_H_
