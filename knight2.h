#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

#define maxDragonBag    14
#define maxLancelotBag  16
#define maxNormalBag    19

enum ItemType
{
    phoenixDownI = 0,
    phoenixDownII,
    phoenixDownIII,
    phoenixDownIV,
    Antidote
};

class BaseKnight;

class BaseItem
{
public:
    virtual bool canUse(BaseKnight *knight) = 0;
    virtual void use(BaseKnight *knight) = 0;
};

class BaseBag
{
public:
    BaseKnight * knight;
    BaseBag();
    BaseBag(ItemType item);

    ItemType itemType;
    BaseBag *next;
    virtual bool insertFirst(BaseItem *item);
    virtual BaseItem *get(ItemType itemType);
    virtual string toString() const;
};

class DragonBag : BaseBag
{

};

class LanclotBag : BaseBag
{
    
};

class PaladinBag : BaseBag
{
    
};

class NormalBag : BaseBag
{
    
};

class BaseOpponent;

enum KnightType
{
    PALADIN = 0,
    LANCELOT,
    DRAGON,
    NORMAL
};

class BaseKnight
{
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    int phoenixdownI;
    int sizeBag;
    BaseBag *bag;
    KnightType knightType;

public:
    BaseKnight();

    int getId() { return id; }
    void setId(int id1) { id = id1; }

    int getHp() { return hp; }
    void setHp(int hp1) { hp = hp1; }

    int getMaxhp() { return maxhp; }
    void setMaxhp(int maxhp1) { maxhp = maxhp1; }

    int getLevel() { return level; }
    void setLevel(int level1) { level = level1; }

    int getGil() { return gil; }
    void setGil(int gil1) { gil = gil1; }

    int getAntidote() { return antidote; }
    void setAntidote(int antidote1) { antidote = antidote1; }

    int getPhoenixdownI() { return phoenixdownI; }
    void setPhoenixdownI(int phoenixdownI1) { phoenixdownI = phoenixdownI1; }

    int getKnightType() { return knightType; }
    void setKnightType(int hpget);

    BaseBag *getBag() { return bag; }
    void setBag(ItemType item, int size);


    void insertBag(ItemType item);
    bool swapBag(ItemType item);
    void deleteBag();
    void print();
    void printlist();

    static BaseKnight *create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
};

class Events;

class ArmyKnights
{
public:
    BaseKnight *arrArmy;
    int sizeArmy;
    ArmyKnights(const string &file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent *opponent);
    bool adventure(Events *events);
    int count() const;
    BaseKnight *lastKnight() const;

    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;

    // void printInfo() const;
    // void printResult(bool win) const;
};

class Events
{
public:
    int *arrEvents;
    int sizeEvents;
    Events(const string &file_events);
    ~Events();

    int count() const;
    int get(int i) const;
};

class KnightAdventure
{
private:
    ArmyKnights *armyKnights;
    Events *events;

public:
    KnightAdventure();
    ~KnightAdventure();

    void loadArmyKnights(const string &);
    void loadEvents(const string &);
    void run();
};

#endif // __KNIGHT2_H__