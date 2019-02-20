#include "StudentWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include "Level.h"
#include <string>
using namespace std;

GameWorld* createStudentWorld(string assetPath)
{
	return new StudentWorld(assetPath);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h and Actor.cpp

StudentWorld::StudentWorld(string assetPath)
: GameWorld(assetPath)
{
    //initialize data members
}

StudentWorld:: ~StudentWorld()
{
    cleanUp();
}

int StudentWorld::init()
{
    //creates Penelope and inserts her into the level at the proper starting location (as specified by the level 01 data file)
    // also must create all of the walls and add them to the level
    
    //for future when you have more than just one level
    
    /*int levelNum = getLevel();
    Level lev(assetPath());
    string levelFile;
    switch(levelNum)
    {
        case 1:
            levelFile = "level01.txt";
            break;
        case 2:
            levelFile = "level02.txt";
            break;
        case 3:
            levelFile = "level03.txt";
            break;
        case 4:
            levelFile = "level04.txt";
            break;
        case 5:
            levelFile = "level05.txt";
            break;
        case 6:
            levelFile = "level06.txt";
            break;
    }
    Level::LoadResult result = lev.loadLevel(levelFile);
    //loop thru and find loc of @ symbol*/
    
    Level lev(assetPath());
    string levelFile = "level01.txt";
    Level::LoadResult result = lev.loadLevel(levelFile);
    if(result == Level::load_fail_file_not_found)
        cerr << "Cannot find level-1.txt data file" << endl;
    else if(result == Level::load_fail_bad_format)
        cerr << "Your level was improperly formatted" << endl;
    else if(result == Level:: load_success)
    {
        cerr << "Successfully loaded level" << endl;
        for(int x =0; x<16; x++)
        {
            for(int y =0; y<16; y++)
            {
                Level::MazeEntry ge = lev.getContentsOf(x,y);
                switch(ge)
                {
                    case Level::empty:
                        break;
                    case Level::player:
                        penelope = new Penelope(x,y);
                        break;
                    case Level::wall:
                        actors.push_back(new Wall(x,y));
                        break;
                }
            }
        }
    }
    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you hit enter.
    // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
    //Must ask Penelope and other actors(walls) to do something
    //doesn't need to check to seee if Penelope has died or not
    vector<Actor*>::iterator iter = actors.begin();
    while(iter!=actors.end())
    {
        ((*iter))->doSomething(); //call each characters doSomething function
        penelope->doSomething();
        iter++;
    }
    return GWSTATUS_CONTINUE_GAME;
    //decLives();
    //return GWSTATUS_PLAYER_DIED;
}

void StudentWorld::cleanUp()
{
    //frees any dynamically allocated data that was allocated during calls to the init(0 or move() method
    //should delete all allocated walls and Penelope
    //StudenWorld class must have both a destructor and cleanUp method
    vector<Actor*>::iterator iter = actors.begin();
    while(iter!=actors.end())
    {
        delete *iter;
        iter = actors.erase(iter);
    }
    delete penelope;
}









