#include "knight2.h"

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void BaseKnight::setKnightType(int hpget)
{
    if (isPrime(hpget))
    {
        knightType = PALADIN;
        return;
    }

    else if (hpget == 888)
    {
        knightType = LANCELOT;
        return;
    }

    else
    {
        int temp = hpget;
        int z = temp % 10;
        temp = temp / 10;
        int y = temp % 10;
        temp = temp / 10;
        int x = temp % 10;

        if ((hpget >= 100 && hpget <= 999) && (x * x + y * y == z * z || z * z + y * y == x * x || x * x + z * z == y * y))
        {
            knightType = DRAGON;
            return;
        }

        else
        {
            knightType = NORMAL;
            return;
        }
    }
}

/* * * BEGIN implementation of class BaseBag * * */

BaseBag::BaseBag()
{
    sizeBag = 0;
    head = nullptr;
}

bool BaseBag::insertFirst(BaseItem *item)
{
    if (maxSize == -1 || sizeBag < maxSize)
    {
        if (maxSize == maxDragonBag && item->itemType == Antidote)
        {
            if (knight -> getId() > 0)
            {
                BaseKnight * beforeKnight = knight - 1;
                beforeKnight -> getBag() -> insertFirst(item);
            }

            else if (knight -> getId() == 0)
            {
                return false;
            }    
        }

        item->next = head;
        head = item;
        sizeBag += 1;
        return true;
    }
    return false;
}
BaseItem *BaseBag::get(ItemType itemType) // coi lai nha
{
    BaseItem *haha = nullptr;
    return haha;
}

string BaseBag::toString() const
{
    return "1";
}

// void BaseBag::insertBag(ItemType item)
// {
//     if (item == phoenixDownI)
//     {
//         classPhoenixI *object = new classPhoenixI();
//         object->next = head;
//         head = object;
//         sizeBag += 1;
//     }
//     else if (item == phoenixDownII)
//     {
//         classPhoenixII *object = new classPhoenixII();
//         object->next = head;
//         head = object;
//         sizeBag += 1;
//     }
//     else if (item == phoenixDownIII)
//     {
//         classPhoenixIII *object = new classPhoenixIII();
//         object->next = head;
//         head = object;
//         sizeBag += 1;
//     }
//     else if (item == phoenixDownIV)
//     {
//         classPhoenixIV *object = new classPhoenixIV();
//         object->next = head;
//         head = object;
//         sizeBag += 1;
//     }
//     else
//     {
//         classAntidote *object = new classAntidote();
//         object->next = head;
//         head = object;
//         sizeBag += 1;
//     }
// }

// void BaseKnight::print()
// {
//     cout << id << " " << hp << " " << maxhp << " " << level << " " << gil << " " << antidote << " " << phoenixdownI << endl;
// }

// void BaseKnight::printlist()
// {
//     BaseBag *temp = bag;
//     while (temp != nullptr)
//     {
//         cout << temp->itemType << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */

BaseKnight::BaseKnight()
{
    bag = new BaseBag();
}

void BaseKnight::print()
{
    cout << id << " " << hp << " " << maxhp << " " << level << " " << gil << " " << antidote << " " << phoenixdownI << endl;
}

void BaseKnight::printlist()
{
    BaseItem *temp = bag->head;
    while (temp != nullptr)
    {
        cout << temp->itemType << " ";
        temp = temp->next;
    }
    cout << endl;
}

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
    newKnight->setBag(Antidote, antidote);
    newKnight->setBag(phoenixDownI, phoenixdownI);
    newKnight -> getBag() -> knight = newKnight; //TO DO
    newKnight -> setKnightType(maxhp);

    return newKnight;
}

string BaseKnight::toString() const
{
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) + ",hp:" + to_string(hp) + ",maxhp:" + to_string(maxhp) + ",level:" + to_string(level) + ",gil:" + to_string(gil) + "," + bag->toString() + ",knight_type:" + typeString[knightType] + "]";
    return s;
}

void BaseKnight::setBag(ItemType item, int size)
{    
    if (size >= 1)
    {
        for (int i = 0; i < size; i++)
        {
            if (item == phoenixDownI)
            {
                classPhoenixI * item = new classPhoenixI();
                bag->insertFirst(item);
            }

            else if (item == phoenixDownII)
            {
                classPhoenixII * item = new classPhoenixII();
                bag->insertFirst(item);
            }

            else if (item == phoenixDownIII)
            {
                classPhoenixIII * item = new classPhoenixIII();
                bag->insertFirst(item);
            }

            else if (item == phoenixDownIV)
            {
                classPhoenixIV * item = new classPhoenixIV();
                bag->insertFirst(item);
            }

            else if (item == Antidote)
            {
                classAntidote * item = new classAntidote();
                bag->insertFirst(item);
            }  
        }
    }

    else
    {
        bag = nullptr;
    }
}

/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */

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

bool ArmyKnights::fight(BaseOpponent * opponent)
{
    BaseKnight * lastKnight = &arrArmy[(this -> sizeArmy) - 1]; //TO DO

    int levelOppo = opponent -> levelO;
    int baseDam = opponent -> baseDamage;

    int gil = lastKnight -> getGil();
    int level = lastKnight -> getLevel();
    int hp = lastKnight -> getHp();

    if (level >= levelOppo)
    {
        gil += opponent->gilIfWin;
        if (gil > 999)
        {
            gil = 999;
        }
        lastKnight -> setGil(gil);
        return true;
    }

    else 
    {
        hp = hp - baseDam * (levelOppo - level);
        if (hp <= 0)
        {
            
        }
        return true;
    }
}

/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class Events * * */
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

/* * * END implementation of class Events * * */

/* * * BEGIN implementation of class KnightAdventure * * */
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


    // for (int i = 0; i < events->sizeEvents; i++)
    // {
    //     int thisEvent = events->arrEvents[i];
    //     BaseKnight lastKnight = armyKnights->arrArmy[armyKnights->sizeArmy - 1];

    //     if (thisEvent >= 1 && thisEvent <= 5)
    //     {
    //         int levelO = (i + thisEvent) % 10 + 1;

    //         if (thisEvent == 1)
    //         {
    //             MadBear * opponent = new MadBear(levelO);
    //             armyKnights->fight(opponent);
    //         }
    //         if (thisEvent == 2)
    //         {
    //             Bandit * opponent = new Bandit(levelO);
    //             armyKnights->fight(opponent);
    //         }
    //         if (thisEvent == 3)
    //         {
    //             LordLupin * opponent = new LordLupin(levelO);
    //             armyKnights->fight(opponent);
    //         }
    //         if (thisEvent == 4)
    //         {
    //             Elf * opponent = new Elf(levelO);
    //             armyKnights->fight(opponent);
    //         }
    //         if (thisEvent == 5)
    //         {
    //             Troll * opponent = new Troll(levelO);
    //             armyKnights->fight(opponent);
    //         }
    //     }
    // }
}

/* * * END implementation of class KnightAdventure * * */