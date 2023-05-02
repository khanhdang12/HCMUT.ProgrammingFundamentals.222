#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

#define maxDragonBag 14
#define maxLancelotBag 16
#define maxNormalBag 19

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
    ItemType itemType;
    BaseItem *next;
    BaseItem()
    {
        next = nullptr;
    }
    virtual bool canUse(BaseKnight *knight) = 0;
    virtual void use(BaseKnight *knight) = 0;
};

class classPhoenixI : public BaseItem
{
public:
    classPhoenixI()
    {
        itemType = phoenixDownI;
        next = nullptr;
    }
    bool canUse(BaseKnight *knight)
    {
        return false;
    }
    void use(BaseKnight *knight)
    {

    }
};

class classPhoenixII : public BaseItem
{
public:
    classPhoenixII()
    {
        itemType = phoenixDownII;
        next = nullptr;
    }
    bool canUse(BaseKnight *knight)
    {
        return false;
    }
    void use(BaseKnight *knight)
    {

    }
};

class classPhoenixIII : public BaseItem
{
public:
    classPhoenixIII()
    {
        itemType = phoenixDownIII;
        next = nullptr;
    }
    bool canUse(BaseKnight *knight)
    {
        return false;
    }
    void use(BaseKnight *knight)
    {

    }
};

class classPhoenixIV : public BaseItem
{
public:
    classPhoenixIV()
    {
        itemType = phoenixDownIV;
        next = nullptr; 
    }
    bool canUse(BaseKnight *knight)
    {
        return false;
    }
    void use(BaseKnight *knight)
    {

    }
};

class classAntidote : public BaseItem
{
public:    
    classAntidote()
    {
        itemType = Antidote;
        next = nullptr;
    }
    bool canUse(BaseKnight *knight)
    {
        return false;
    }
    void use(BaseKnight *knight)
    {

    }
};

class BaseBag
{
public:
    BaseKnight *knight;
    BaseItem *head;
    int sizeBag;
    int maxSize;
    BaseBag();

    // void insertBag(ItemType item);
    // bool swapBag(ItemType item);
    // void deleteBag();
    void print();
    void printlist();
    virtual bool insertFirst(BaseItem *item); 
    virtual BaseItem *get(ItemType itemType);
    virtual string toString() const;
    // virtual ~BaseBag() {}
};

class DragonBag : public BaseBag
{
    DragonBag()
    {
        maxSize = maxDragonBag;
    }

    // bool insertFirst(BaseItem *item)
    // {
    //     return true;
    // }

    BaseItem *get(ItemType itemType)
    {
        BaseItem * haha = nullptr;
        return haha;
    }
    string toString() 
    {
        return "1";
    }
};

class LancelotBag : public BaseBag
{
    LancelotBag()
    {
        maxSize = maxLancelotBag;
    }

    // bool insertFirst(BaseItem *item)
    // {
    //     return true;
    // }
    BaseItem *get(ItemType itemType)
    {
        BaseItem * haha = nullptr;
        return haha;
    }
    string toString() 
    {
        return "1";
    }
};

class PaladinBag : public BaseBag
{
    PaladinBag()
    {
        maxSize = -1;
    }

    // bool insertFirst(BaseItem *item)
    // {
    //     return true;
    // }
    BaseItem *get(ItemType itemType)
    {
        BaseItem * haha = nullptr;
        return haha;
    }
    string toString() 
    {
        return "1";
    }
};

class NormalBag : public BaseBag
{
    NormalBag()
    {
        maxSize = maxNormalBag;
    }

    // bool insertFirst(BaseItem *item)
    // {
    //     return true;
    // }
    BaseItem *get(ItemType itemType)
    {
        BaseItem * haha = nullptr;
        return haha;
    }
    string toString() 
    {
        return "1";
    }
};

class BaseOpponent
{
public:
    int baseDamage;
    int gilIfWin;
    int levelO;
};

class MadBear: public BaseOpponent
{   
public:
    MadBear(int levelIn)
    {
        baseDamage = 10;
        gilIfWin = 100;
        levelO = levelIn;
    }
};

class Bandit: public BaseOpponent
{
public:
    Bandit(int levelIn)
    {
        baseDamage = 15;
        gilIfWin = 150;
        levelO = levelIn;
    }
};

class LordLupin: public BaseOpponent
{
public:
    LordLupin(int levelIn)
    {
        baseDamage = 45;
        gilIfWin = 450;
        levelO = levelIn;
    }
};

class Elf: public BaseOpponent
{
public:
    Elf(int levelIn)
    {
        baseDamage = 75;
        gilIfWin = 750;
        levelO = levelIn;
    }
};

class Troll: public BaseOpponent
{
public:
    Troll(int levelIn)
    {
        baseDamage = 95;
        gilIfWin = 800;
        levelO = levelIn;
    }
};

class Tornbery: public BaseOpponent
{

};

class QueenOfCards: public BaseOpponent
{

};

class NinaDeRings:public BaseOpponent
{

};

class DurianGarden:public BaseOpponent
{

};

class OmegaWeapon:public BaseOpponent
{

};

class Hades:public BaseOpponent
{

};

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
    BaseBag *bag;
    KnightType knightType;

public:
    BaseKnight();
    ~BaseKnight()
    {
        delete bag;
    }

    void print();
    void printlist();

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