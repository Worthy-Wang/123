#ifndef _WARCRAFT_WARCRAFTWORLD_H_
#define _WARCRAFT_WARCRAFTWORLD_H_
#include "Headquarters.h"
#include "GameTime.h"

namespace warcraft
{

class WarcraftWorld
{
    Headquarters *_red;
    Headquarters *_blue;
    size_t _caseNum; //读取数据组号
    size_t _minHp;   //生成勇士的最小生命值
public:
    WarcraftWorld()
        : _red(NULL), _blue(NULL)
    {
        init();
    }

    ~WarcraftWorld()
    {
        if (_red)
            delete _red;
        if (_blue)
            delete _blue;
    }

    void startGame();

private:
    void init();
    void createAndShow(Headquarters *);
};



} //end of namespace warcraft

#endif