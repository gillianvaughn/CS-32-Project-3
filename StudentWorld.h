#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include <string>
#include <vector>

using namespace std;

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class Actor;
class Penelope;

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetPath);
    virtual int init();
    virtual int move();
    virtual void cleanUp();
    ~StudentWorld();
private:
    vector<Actor*> actors;
    Penelope* penelope;
};

#endif // STUDENTWORLD_H_
