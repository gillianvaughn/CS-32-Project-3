#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp
using namespace std;

Actor::Actor(int imageID, double startX, double startY, int dir, double size, int depth, int state):GraphObject(imageID, startX, startY, dir, depth), actorState(state)
{
    //oh shit whaddup
}
int Actor::getState()const
{
    return actorState;
}
void Actor::setState(int state)
{
    actorState = state;
}
void Actor::doSomething()
{
    //should be implemented in each of the actor
}
Wall::Wall(double level_x, double level_y): Actor(IID_WALL, SPRITE_WIDTH * level_x, SPRITE_HEIGHT * level_y, 0, 0, 3)
{
    //setSize();
}
void Wall::doSomething()
{
    // the wall is supposed to do nothing!!
    
}
Penelope::Penelope(double level_x, double level_y): Actor(IID_PLAYER, SPRITE_WIDTH * level_x, SPRITE_HEIGHT * level_y, 0, 0, 1)
{
    
}
void Penelope::setWorld(StudentWorld* world)
{
    this->world = world;
}
StudentWorld* Penelope::getWorld()
{
    return world;
}
void Penelope::doSomething()
{
    if(getState() == DEAD)
        return;
    int key;
    if(getWorld()->getKey(key))
    {
        switch(key)
        {
            case KEY_PRESS_LEFT:
                moveX(-4);
                setDirection(180);
                break;
            case KEY_PRESS_RIGHT:
                moveX(4);
                setDirection(0);
                break;
            case KEY_PRESS_UP:
                moveY(4);
                setDirection(90);
                break;
            case KEY_PRESS_DOWN:
                moveY(-4);
                setDirection(270);
                break;
        }
    }
}

void Penelope::moveX(int movement)
{
    //check if penelope can do the move in this direction
    if(getX() + movement < VIEW_WIDTH || getX() + movement >=0)
        moveTo(getX()+movement, getY());
}

void Penelope::moveY(int movement)
{
    if(getY()+ movement < VIEW_HEIGHT || getY() + movement >=0)
        moveTo(getX(), getY()+movement);
}













