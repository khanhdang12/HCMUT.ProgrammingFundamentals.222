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
        knightType =  PALADIN;
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
            knightType =  DRAGON;
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

BaseBag::BaseBag() //Chua co deconstruct
{
    next = nullptr;
}

BaseBag::BaseBag(ItemType item)
{
    itemType = item;
    next = nullptr;
}

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */
BaseKnight::BaseKnight() //Chua co deconstruct
{
    sizeBag = 0;
    bag = new BaseBag();
    bag = nullptr;
}

void BaseKnight::insertBag(ItemType item)
{
    sizeBag += 1;
    BaseBag *newbag = new BaseBag(item);
    newbag->next = bag;
    bag = newbag;
}

bool BaseKnight::swapBag(ItemType item)
{
    if (bag == nullptr)
    {
        return false;
    }

    if (bag->itemType == item)
    {
        return true;
    }

    BaseBag *first = bag;
    BaseBag *temp = bag->next;
    while (temp != nullptr)
    {
        if (temp->itemType == item)
        {
            ItemType temp2 = temp->itemType;
            temp->itemType = first->itemType;
            first->itemType = temp2;
            return true;
        }
        temp = temp->next;
    }

    return false;
}

void BaseKnight::deleteBag()
{
    if (bag == nullptr)
    {
        return;
    }
    sizeBag -= 1;
    BaseBag *temp = bag;
    bag = bag->next;
    delete temp;
}

void BaseKnight::print()
{
    cout << id << " " << hp << " " << maxhp << " " << level << " " << gil << " " << antidote << " " << phoenixdownI << endl;
}

void BaseKnight::printlist()
{
    BaseBag *temp = bag;
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

    int num1 = newKnight->getPhoenixdownI();
    newKnight->setBag(phoenixDownI, num1);

    int num2 = newKnight->getAntidote();
    newKnight->setBag(Antidote, num2);

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
            insertBag(item);
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
        arrArmy[i] = * create(i + 1, hp, level, gil, antidote, phoenixdownI);
    }
    fp.close();
}

ArmyKnights::~ArmyKnights()
{
    delete[] arrArmy;
}

int ArmyKnights::count() const
{
    return sizeArmy;
}

BaseKnight * ArmyKnights::lastKnight() const
{
    if (sizeArmy <= 0)
    {
        return nullptr;
    }

    return arrArmy + (sizeArmy - 1);
}


// void ArmyKnights::printInfo() const
// {
//     cout << "No. knights: " << this->count();
//     if (this->count() > 0)
//     {
//         BaseKnight *lknight = lastKnight(); // last knight
//         cout << ";" << lknight->toString();
//     }
//     cout << ";PaladinShield:" << this->hasPaladinShield()
//          << ";LancelotSpear:" << this->hasLancelotSpear()
//          << ";GuinevereHair:" << this->hasGuinevereHair()
//          << ";ExcaliburSword:" << this->hasExcaliburSword()
//          << endl
//          << string(50, '-') << endl;
// }

// void ArmyKnights::printResult(bool win) const
// {
//     cout << (win ? "WIN" : "LOSE") << endl;
// }

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

/* * * END implementation of class ArmyKnights * * */

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
    // int len = armyKnights->sizeArmy;
    // for (int i = 0; i < len; i++)
    // {
    //     armyKnights->arrArmy[i].print();
    //     armyKnights->arrArmy[i].printlist();
    // }
}

/* * * END implementation of class KnightAdventure * * */