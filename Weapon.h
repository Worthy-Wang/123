#ifndef _WARCRAFT_WEAPON_H_
#define _WARCRAFT_WEAPON_H_
#include "Type.h"
#include <iostream>
#include <string>
using std::string;

namespace warcraft
{


/**************************Weapon*******************************/
class Weapon
{
protected:
    WeaponType _type;
    string _name;
    size_t _attack;
public:
    Weapon(WeaponType type, string name)
    :_type(type)
    ,_name(name)
    {}
    virtual ~Weapon(){}

    WeaponType getType() const { return _type; }
    string getName() const { return _name; }
    size_t getAttackValue() const { return _attack; }
};


class Sword:public Weapon
{
public:
    Sword()
    :Weapon(SWORD ,"Sword")
    {}
};

class Bomb:public Weapon
{
public:
    Bomb()
    :Weapon(BOMB, "Bomb")
    {}
};

class Arrow:public Weapon
{
public: 
    Arrow()
    :Weapon(ARROW, "Arrow")
    {}
};


/**************************View层*******************************/
class WeaponView
{
protected:
    WeaponPtr _weapon;
public:
    WeaponView(WeaponPtr weapon)
    :_weapon(weapon)
    {}
    virtual ~WeaponView(){}

    virtual void showWeapon() const {}
};


class SwordView:public WeaponView
{
public:
    SwordView(WeaponPtr weapon)
    :WeaponView(weapon)
    {}

    void showWeapon()const 
    {
        std::cout << "Sword";
    }
};

class BombView:public WeaponView
{
public:
    BombView(WeaponPtr weapon)
    :WeaponView(weapon)
    {}

    void showWeapon()const 
    {
        std::cout << "Bomb";
    }
};


class ArrowView:public WeaponView
{
public:
    ArrowView(WeaponPtr weapon)
    :WeaponView(weapon)
    {}

    void showWeapon()const 
    {
        std::cout << "Arrow";
    }
};



}//end of namespace warcraft


#endif 