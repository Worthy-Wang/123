#include "WarcraftWorld.h"
#include <iostream>
#include <memory>
using namespace warcraft;

//Weapon.h测试程序
void test0()
{
    WeaponPtr weapon(new Sword());
    WeaponViewPtr pView(new ArrowView(weapon));
    pView->showWeapon();
}

//Warror.h测试程序
void test1()
{
    int x = 100;
    WarriorPtr dragon(new Dragon(RED, 3, 3, x));
    cout << dragon->getMorale() << endl;

    WarriorViewPtr view(new DragonView(dragon));
    view->show();
}

//GameTime.h
void test2()
{
    GameTime::getInstance()->showTime();
    GameTime::getInstance()->updateTime();
    GameTime::getInstance()->showTime();
}

//GameConfig.h
void test3()
{
    vector<WarriorType> initHpOrder{DRAGON, NINJA, ICEMAN, LION, WOLF};
    GameConfig::getInstance()->setInitWarriorOrder(initHpOrder.begin(), initHpOrder.end());

    GameConfig::getInstance()->readFromFile("warcraft.conf");
    cout << GameConfig::getInstance()->getMinHp(2) << endl;
    GameConfig::getInstance()->print();
}

//Headquarters.h

void test4()
{
    Headquarters *red = new Headquarters(RED, 20);
    vector<WarriorType> initHpOrder{DRAGON, NINJA, ICEMAN, LION, WOLF};
    vector<WarriorType> redCreateorder{ICEMAN, LION, WOLF, NINJA, DRAGON};
    GameConfig::getInstance()->setInitWarriorOrder(initHpOrder.begin(), initHpOrder.end());
    GameConfig::getInstance()->readFromFile("warcraft.conf");
    // GameConfig::getInstance()->print(); //进行检测
    red->setWarriorCreateOrder(redCreateorder.begin(), redCreateorder.end());
    WarriorPtr warrior = red->createWarrior(DRAGON);
    WarriorViewPtr warriorView(new DragonView(warrior));

    // HeadquartersView *view = new HeadquartersView(red);

}

//WarcraftWorld
void test5()
{
    WarcraftWorld world;
    world.startGame();


}

int main()
{
    test5();
    return 0;
}