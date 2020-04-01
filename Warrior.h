#ifndef _WARCRAFT_WARRIOR_H_
#define _WARCRAFT_WARRIOR_H_
#include "Type.h"
#include "Weapon.h"
#include <iostream>
#include <vector>
#include <memory>
using std::vector;

namespace warcraft
{

/**************************Warrior及其派生类Model*******************************/
class Warrior
{
protected:
    ColorType _color;
    string _name;
    size_t _id;
    size_t _hp;
    WarriorType _type;
    vector<WeaponPtr> _weapons;
public:
    Warrior(ColorType color, string name, size_t id, size_t hp, WarriorType type)
        : _color(color), _name(name), _id(id), _hp(hp), _type(type)
    {}
    virtual ~Warrior(){}

    ColorType getColor() const { return _color; }
    string getName() const { return _name; }
    size_t getId() const { return _id; }
    size_t getHp() const { return _hp; }
    WarriorType getType() const { return _type; }

    virtual double getMorale()  { return -1;}
    virtual size_t getLoyalty() { return -1;}

    //Weapon
    vector<WeaponPtr>& getWeapons()  { return _weapons;} 
    void setWeapon(WeaponPtr weapon) { _weapons.push_back(weapon); }
};


class Dragon : public Warrior
{
    double _morale;
public:
    Dragon(ColorType color, size_t id, size_t hp, double baseHp)
    :Warrior(color, "Dragon", id, hp, DRAGON)
    ,_morale(baseHp/hp)
    {}

    double getMorale()  { return _morale; }
};


class Ninja : public Warrior
{
public:
    Ninja(ColorType color, size_t id, size_t hp, double baseHp)
    :Warrior(color, "Ninja", id, hp, NINJA)
    {

    }
};


class Iceman : public Warrior
{
public:
    Iceman(ColorType color, size_t id, size_t hp, double baseHp)
    :Warrior(color, "Iceman", id, hp, ICEMAN)
    {

    }
};


class Lion : public Warrior
{
    size_t _loyalty;
public:
    Lion(ColorType color, size_t id, size_t hp, size_t baseHp)
    :Warrior(color, "Lion", id, hp, LION)
    ,_loyalty(baseHp)
    {}

    size_t getLoyalty()  { return _loyalty; }
};


class Wolf : public Warrior
{
public:
    Wolf(ColorType color, size_t id, size_t hp, double baseHp)
    :Warrior(color, "Wolf", id, hp, WOLF)
    {
        
    }
};


/**************************WarriorView视图层*******************************/
class WarriorView
{
protected:
    WarriorPtr _warrior;
public:
    WarriorView(WarriorPtr warrior)
    :_warrior(warrior)
    {}

    virtual ~WarriorView(){}
    virtual void show() const = 0;
};

class DragonView: public WarriorView
{
public:
    DragonView(WarriorPtr warrior)
    :WarriorView(warrior)
    {}

    void show() const 
    {
        std::cout << toString(_warrior->getColor()) << " " << toString(_warrior->getType()) << " " << _warrior->getId() << " born with strength " << _warrior->getHp() << ",";
    }
};

class NinjaView: public WarriorView
{
public:
    NinjaView(WarriorPtr warrior)
    :WarriorView(warrior)
    {}

    void show() const 
    {
        std::cout << toString(_warrior->getColor()) << " " << toString(_warrior->getType()) << " " << _warrior->getId() << " born with strength " << _warrior->getHp() << ",";
    }
};

class IcemanView: public WarriorView
{
public:
    IcemanView(WarriorPtr warrior)
    :WarriorView(warrior)
    {}

    void show() const 
    {
        std::cout << toString(_warrior->getColor()) << " " << toString(_warrior->getType()) << " " << _warrior->getId() << " born with strength " << _warrior->getHp() << ",";
    }
};

class WolfView: public WarriorView
{
public:
    WolfView(WarriorPtr warrior)
    :WarriorView(warrior)
    {}

    void show() const 
    {
        std::cout << toString(_warrior->getColor()) << " " << toString(_warrior->getType()) << " " << _warrior->getId() << " born with strength " << _warrior->getHp() << ",";
    }
};

class LionView: public WarriorView
{
public:
    LionView(WarriorPtr warrior)
    :WarriorView(warrior)
    {}

    void show() const 
    {
        std::cout << toString(_warrior->getColor()) << " " << toString(_warrior->getType()) << " " << _warrior->getId() << " born with strength " << _warrior->getHp() << ",";
    }
};



} //end of namespace warcraft

#endif