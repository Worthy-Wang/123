#include "Headquarters.h"

namespace warcraft
{


/*************************定义成员函数*********************************/
WarriorPtr Headquarters::createWarrior(WarriorType type)
{
    size_t hp = GameConfig::getInstance()->getInitWarriorHp(GameConfig::getInstance()->currentGroupId(), type);
    _baseHp -= hp;
    WarriorPtr warrior;
    WarriorViewPtr warriorView;

    switch (type)
    {
    case DRAGON:
    {
        warrior.reset(new Dragon(getColor(), getWarriorId(), hp, getBaseHp()));
        warriorView.reset(new DragonView(warrior));
        break;
    }
    case NINJA:
    {
        warrior.reset(new Ninja(getColor(), getWarriorId(), hp, getBaseHp()));
        warriorView.reset(new NinjaView(warrior));
        break;
    }
    case ICEMAN:
    {
        warrior.reset(new Iceman(getColor(), getWarriorId(), hp, getBaseHp()));
        warriorView.reset(new IcemanView(warrior));
        break;
    }
    case LION:
    {
        warrior.reset(new Lion(getColor(), getWarriorId(), hp, getBaseHp()));
        warriorView.reset(new LionView(warrior));
        break;
    }
    case WOLF:
    {
        warrior.reset(new Wolf(getColor(), getWarriorId(), hp, getBaseHp()));
        warriorView.reset(new WolfView(warrior));
        break;
    }
    default:
        cout << "Warrior Type ERROR!" << endl;
        break;
    }

    _warriors.push_back(warrior);
    _warriorViews[warrior] = warriorView;
    _warriorTypeAmounts[type]++;

    return warrior;
}

WeaponPtr Headquarters::createWeapon(size_t number)
{
    WeaponPtr weapon;
    WeaponViewPtr weaponView;
    switch (number)
    {
    case 0:
    {
        weapon.reset(new Sword());
        weaponView.reset(new SwordView(weapon));
        break;
    }
    case 1:
    {
        weapon.reset(new Bomb());
        weaponView.reset(new BombView(weapon));
        break;
    }
    case 2:
    {
        weapon.reset(new Arrow());
        weaponView.reset(new ArrowView(weapon));
        break;
    }
    default:
        cout << "Headquarters::createWeapon ERROR!" << endl;
        break;
    }
    _weaponViews[weapon] = weaponView;
    return weapon;
}




}