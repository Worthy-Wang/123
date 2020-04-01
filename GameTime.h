#ifndef _WARCRAFT_GAMETIME_H_
#define _WARCRAFT_GAMETIME_H_
#include <stdio.h>
#include <stdlib.h>

namespace warcraft
{

class GameTime
{
    static GameTime* _pInstance;
    size_t _hour;
public:

    static GameTime* getInstance()
    {
        return _pInstance;
    }

    static void destory()
    {
        if (_pInstance)
        {
            delete _pInstance;
            _pInstance  = NULL;
        }
    }

    size_t getTime() const { return _hour; }
    void showTime() const { printf("00%ld", _hour); }
    void updateTime() { _hour++; }
private:
    GameTime():_hour(0) { atexit(destory); }
    ~GameTime(){}
};






}//end of namespace warcraft


#endif 