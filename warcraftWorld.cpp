#include "WarcraftWorld.h"

namespace warcraft
{
//注意create创建武士一定会成功，不构成创建条件的话时无法进入create语句的
void WarcraftWorld::createAndShow(Headquarters *head)
{
    //基地生命元少于当前创造的勇士生命值时，自动跳转
    while (head->getBaseHp() < GameConfig::getInstance()->getInitWarriorHp(_caseNum, head->getWarriorType()))
        head->nextWarriorType();
    //创建勇士
    WarriorPtr warrior = head->createWarrior(head->getWarriorType());
    WarriorViewPtr warriorView;

    //设置武器
    switch (head->getWarriorType())
    {
    case DRAGON:
    {
        WeaponPtr weapon = head->createWeapon(head->getWarriorId() % 3);
        warrior->setWeapon(weapon);
        warriorView.reset(new DragonView(warrior));
        HeadquartersView headView(head);
        //show
        warriorView->show();
        headView.show();
        cout << "It has a " << weapon->getName() << " and it's loyalty is " << warrior->getMorale() << endl;
        break;
    }
    case ICEMAN:
    {
        WeaponPtr weapon = head->createWeapon(head->getWarriorId() % 3);
        warrior->setWeapon(weapon);
        warriorView.reset(new DragonView(warrior));
        HeadquartersView headView(head);
        //show
        warriorView->show();
        headView.show();
        cout << "It has a " << weapon->getName() << endl;
        break;
    }
    case LION:
    {
        warriorView.reset(new LionView(warrior));
        HeadquartersView headView(head);
        //show
        warriorView->show();
        headView.show();
        cout << "It's loyalty is " << warrior->getLoyalty() << endl;
        break;
    }
    case NINJA:
    {
        WeaponPtr weapon1 = head->createWeapon(head->getWarriorId() % 3);
        WeaponPtr weapon2 = head->createWeapon((head->getWarriorId() + 1) % 3);
        warrior->setWeapon(weapon1);
        warriorView.reset(new DragonView(warrior));
        HeadquartersView headView(head);
        //show
        warriorView->show();
        headView.show();
        cout << "It has a " << weapon1->getName() << " and a " << weapon2->getName() << endl;
        break;
    }
    case WOLF:
    {
        warriorView.reset(new WolfView(warrior));
        HeadquartersView headView(head);
        //show
        warriorView->show();
        headView.show();
        break;
    }
    }
    head->nextWarriorType();
    head->nextWarriorId();
}

void WarcraftWorld::startGame()
{
    bool redFlag = true, blueFlag = true; //为false时表示已经认输，停止创造
    while (redFlag || blueFlag)
    {
        //红方
        if (_red->getBaseHp() >= _minHp)
        {
            GameTime::getInstance()->showTime();
            cout << " ";
            createAndShow(_red);
        }
        else
        {
            if (redFlag == true)
            {
                GameTime::getInstance()->showTime();
                cout << " ";
                cout << "red headquarters stops making warriors" << endl;
                redFlag = false;
            }
        }

        //蓝方
        if (_blue->getBaseHp() >= _minHp)
        {
            GameTime::getInstance()->showTime();
            cout << " ";
            createAndShow(_blue);
        }
        else
        {
            if (blueFlag == true)
            {
                GameTime::getInstance()->showTime();
                cout << " ";
                cout << "blue headquarters stops making warriors" << endl;
                blueFlag = false;
            }
        }
        GameTime::getInstance()->updateTime();
    }
}

void WarcraftWorld::init()
{
    vector<WarriorType> initHpOrder{DRAGON, NINJA, ICEMAN, LION, WOLF};
    vector<WarriorType> redCreateorder{ICEMAN, LION, WOLF, NINJA, DRAGON};
    vector<WarriorType> blueCreateorder{LION, DRAGON, NINJA, ICEMAN, WOLF};

    GameConfig::getInstance()->setInitWarriorOrder(initHpOrder.begin(), initHpOrder.end());
    GameConfig::getInstance()->readFromFile("warcraft.conf");
    GameConfig::getInstance()->print(); //进行检测

    _caseNum = GameConfig::getInstance()->currentGroupId();
    _minHp = GameConfig::getInstance()->getMinHp(_caseNum);
    size_t baseHp = GameConfig::getInstance()->getInitBaseHp(_caseNum);
    _red = new Headquarters(RED, baseHp);
    _blue = new Headquarters(BLUE, baseHp);
    _red->setWarriorCreateOrder(redCreateorder.begin(), redCreateorder.end());
    _blue->setWarriorCreateOrder(blueCreateorder.begin(), blueCreateorder.end());
}


} // namespace warcraft