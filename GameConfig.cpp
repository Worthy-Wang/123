#include "GameConfig.h"

namespace warcraft
{

GameConfig *GameConfig::_pInstance = new GameConfig();
/************************GameConfig定义*****************************/
void GameConfig::readFromConsole()
{
    cout << "please input data:" << endl;
    readFromStream(std::cin);
}

void GameConfig::readFromFile(const string filename)
{
    std::ifstream ifs(filename, std::ifstream::in);
    if (!ifs.good())
    {
        cout << filename << " open ERROR!" << endl;
        exit(-1);
    }
    readFromStream(ifs);
    ifs.close();
}

void GameConfig::readFromStream(std::istream &is)
{
    while (is.good())
    {
        nextGroupId(); //每一次读新数据组时 Case 组数++
        InitData group;
        //读取第一行 组数
        size_t caseNum;
        is >> caseNum;

        //读取第二行 基地生命元
        is >> group._initBaseHp;

        //读取第三行 武士初始生命值
        size_t min = 65536;
        for (size_t i = 0; i < _initWarriorOrder.size(); i++)
        {
            is >> group._initWarriorHp[_initWarriorOrder[i]];
            if (min > group._initWarriorHp[_initWarriorOrder[i]])
                min = group._initWarriorHp[_initWarriorOrder[i]];
        }
        group._minHp = min;

        _groups.push_back(std::move(group));
    }
}

void GameConfig::print() const
{
    for (size_t i = 0; i < _groups.size(); i++)
    {
        cout << i + 1 << endl;
        cout << _groups[i]._initBaseHp << endl;
        for (auto &e : _groups[i]._initWarriorHp)
            cout << e.second << " ";
        cout << endl;
        cout << "---------------" << endl;
    }
}

} // namespace warcraft