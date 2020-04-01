#ifndef _WARCRAFT_GAMECONFIG_H_
#define _WARCRAFT_GAMECONFIG_H_
#include "Type.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <istream>
#include <algorithm>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::stringstream;
using std::vector;

namespace warcraft
{

struct InitData
{
    size_t _initBaseHp;                      //基地的初始生命元
    size_t _minHp;                           //创建武士所需的最小生命元
    map<WarriorType, size_t> _initWarriorHp; //不同武士的初始生命值
};

class GameConfig
{
    static GameConfig *_pInstance;
    vector<WarriorType> _initWarriorOrder; //对于武士的初始化顺序
    size_t _currentGroupId;                //当前Case 组号
    vector<InitData> _groups;              //组的信息

public:
    static GameConfig *getInstance()
    {
        return _pInstance;
    }
    static void destory()
    {
        if (_pInstance)
        {
            delete _pInstance;
            _pInstance = NULL;
        }
    }

    template <typename Iterator>
    void setInitWarriorOrder(Iterator beg, Iterator end)
    {
        while (beg != end)
        {
            _initWarriorOrder.push_back(*beg++);
        }
    }

    size_t groupSize() const { return _groups.size(); }                                                                   //返回组的数量
    size_t currentGroupId() const { return _currentGroupId; }                                                             //返回当前组号
    size_t getInitBaseHp(size_t caseNum) { return _groups[caseNum - 1]._initBaseHp; }                                     //返回基地初始生命元
    size_t getInitWarriorHp(size_t caseNum, WarriorType warrior) { return _groups[caseNum - 1]._initWarriorHp[warrior]; } //返回武士初始生命值
    size_t getMinHp(size_t caseNum) const { return _groups[caseNum - 1]._minHp; }

    void readFromConsole();
    void readFromFile(const string filename);
    void readFromStream(std::istream &);

    //测试打印函数
    void print() const;

private:
    GameConfig() : _currentGroupId(0) { atexit(destory); }
    ~GameConfig() {}
    void nextGroupId() { _currentGroupId++; } //组增加
};



} //end of namespace warcraft

#endif