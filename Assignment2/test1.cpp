#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

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
    BaseBag();

    void insertBag(ItemType item);
    bool swapBag(ItemType item);
    void deleteBag();
    void print();
    void printlist();
    // virtual bool insertFirst(BaseItem *item); // co the bo do vao tui hay khong tuy theo gioi han tui
    // virtual BaseItem *get(ItemType itemType);
    // virtual string toString() const;
};

BaseBag::BaseBag()
{
    sizeBag = 0;
    head = nullptr;
}

void BaseBag::insertBag(ItemType item)
{
    if (item == phoenixDownI)
    {
        classPhoenixI * object = new classPhoenixI();
        object->next = head;
        head = object;
        sizeBag += 1;
    }
    else if (item == phoenixDownII)
    {
        classPhoenixII * object = new classPhoenixII();        
        object->next = head;
        head = object;
        sizeBag += 1;
    }
    else if (item == phoenixDownIII)
    {
        classPhoenixIII * object = new classPhoenixIII();
        object->next = head;
        head = object;
        sizeBag += 1;
    }
    else if (item == phoenixDownIV)
    {
        classPhoenixIV * object = new classPhoenixIV();
        object->next = head;
        head = object;
        sizeBag += 1;
    }
    else
    {
        classAntidote * object = new classAntidote();
        object->next = head;
        head = object;
        sizeBag += 1;
    }
}


// class DragonBag : BaseBag
// {
//     virtual bool insertFirst(BaseItem *item); // co the bo do vao tui hay khong tuy theo gioi han tui
//     virtual BaseItem *get(ItemType itemType);
//     virtual string toString() const;
// };

// class LancelotBag : BaseBag
// {
//     virtual bool insertFirst(BaseItem *item); // co the bo do vao tui hay khong tuy theo gioi han tui
//     virtual BaseItem *get(ItemType itemType);
//     virtual string toString() const;
// };

// class PaladinBag : BaseBag
// {
//     virtual bool insertFirst(BaseItem *item); // co the bo do vao tui hay khong tuy theo gioi han tui
//     virtual BaseItem *get(ItemType itemType);
//     virtual string toString() const;
// };

// class NormalBag : BaseBag
// {
//     virtual bool insertFirst(BaseItem *item); // co the bo do vao tui hay khong tuy theo gioi han tui
//     virtual BaseItem *get(ItemType itemType);
//     virtual string toString() const;
// };

// class BaseOpponent;

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

void BaseKnight::print()
{
    cout << id << " " << hp << " " << maxhp << " " << level << " " << gil << " " << antidote << " " << phoenixdownI << endl;
}

void BaseKnight::printlist()
{
    BaseItem *temp = bag -> head;
    while (temp != nullptr)
    {
        cout << temp->itemType << " ";
        temp = temp->next;
    }
    cout << endl;
}

BaseKnight::BaseKnight()
{
    bag = new BaseBag();
}

//BaseKnight * BaseNight create()
static BaseKnight *create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
{
    BaseKnight *newKnight = new BaseKnight();
    newKnight->setId(id);
    newKnight->setHp(maxhp);
    newKnight->setMaxhp(maxhp);
    newKnight->setLevel(level);
    newKnight->setGil(gil);
    newKnight->setAntidote(antidote);
    newKnight->setPhoenixdownI(phoenixdownI);

    int num1 = newKnight->getPhoenixdownI();
    newKnight->setBag(phoenixDownI, num1);

    int num2 = newKnight->getAntidote();
    newKnight->setBag(Antidote, num2);

    return newKnight;
}

void BaseKnight::setBag(ItemType item, int size)
{
    if (size >= 1)
    {
        for (int i = 0; i < size; i++)
        {
            bag->insertBag(item);
        }
    }

    else
    {
        bag = nullptr;
    }
}

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

Events::Events(const string &file_events)
{
    ifstream fp;
    fp.open(file_events);
    fp >> sizeEvents;
    arrEvents = new int[sizeEvents];
    int event;
    for (int i = 0; i < sizeEvents; i++)
    {
        fp >> event;
        arrEvents[i] = event;
    }
    fp.close();
}

Events::~Events()
{
    delete[] arrEvents;
}

class ArmyKnights
{
public:
    BaseKnight *arrArmy;
    int sizeArmy;
    ArmyKnights(const string &file_armyknights);
    ~ArmyKnights();
    // bool fight(BaseOpponent *opponent);
    // bool adventure(Events *events);
    // int count() const;
    // BaseKnight *lastKnight() const;

    // bool hasPaladinShield() const;
    // bool hasLancelotSpear() const;
    // bool hasGuinevereHair() const;
    // bool hasExcaliburSword() const;
    // void printInfo() const;
    // void printResult(bool win) const;
};

ArmyKnights::ArmyKnights(const string &file_armyknights)
{
    ifstream fp;
    fp.open(file_armyknights);
    fp >> sizeArmy;
    arrArmy = new BaseKnight[sizeArmy];
    int hp, level, phoenixdownI, gil, antidote;
    for (int i = 0; i < sizeArmy; i++)
    {
        fp >> hp >> level >> phoenixdownI >> gil >> antidote;
        arrArmy[i] = *create(i + 1, hp, level, gil, antidote, phoenixdownI);
    }
    fp.close();
}

ArmyKnights::~ArmyKnights()
{
    delete[] arrArmy;
}

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

KnightAdventure::KnightAdventure()
{
    armyKnights = nullptr;
    events = nullptr;
}

KnightAdventure::~KnightAdventure()
{
    delete armyKnights;
    delete events;
}

void KnightAdventure::loadArmyKnights(const string &file_armyknights)
{
    armyKnights = new ArmyKnights(file_armyknights);
}

void KnightAdventure::loadEvents(const string &file_events)
{
    events = new Events(file_events);
}

void KnightAdventure::run()
{
    cout << events -> sizeEvents << endl;
    for (int i = 0; i < events -> sizeEvents; i++)
    {
        cout << events -> arrEvents[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < armyKnights->sizeArmy; i++)
    {
        armyKnights->arrArmy[i].print();
        armyKnights->arrArmy[i].printlist();
    }
    cout << endl;
}

int main()
{
    KnightAdventure *knightAdventure = new KnightAdventure();
    knightAdventure->loadArmyKnights("tc1_armyknights");
    knightAdventure->loadEvents("tc1_events");
    knightAdventure->run();
    delete knightAdventure;
}