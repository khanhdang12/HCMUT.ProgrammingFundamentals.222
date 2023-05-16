#include "knight2.h"

string output = "";

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

KnightType makeKnightType(int hpget)
{
    if (isPrime(hpget))
    {
        return PALADIN;
    }

    else if (hpget == 888)
    {
        return LANCELOT;
    }

    else
    {
        int temp = hpget;
        int z = temp % 10;
        temp = temp / 10;
        int y = temp % 10;
        temp = temp / 10;
        int x = temp % 10;

        if (((x > 0) && (y > 0) && (z > 0)) && (x * x + y * y == z * z || z * z + y * y == x * x || x * x + z * z == y * y))
        {
            return DRAGON;
        }

        else
        {
            return NORMAL;
        }
    }
}

/* * * BEGIN implementation of class BaseBag * * */

BaseBag::BaseBag()
{
    knight = nullptr;
    sizeBag = 0;
    head = nullptr;
}

BaseBag::~BaseBag()
{
    if (sizeBag > 0)
    {
        BaseItem *current = head;
        while (current != nullptr)
        {
            BaseItem *temp = current;
            current = current->next;
            delete temp;
        }
    }
}

bool BaseBag::insertFirst(BaseItem *item)
{
    int max = knight->maxSize;
    if (max == -1 || sizeBag < max)
    {
        if (max == maxDragonBag && item->itemType == ANTIDOTE)
        {
            if (knight->getId() > 0)
            {
                BaseKnight *beforeKnight = knight - 1;
                beforeKnight->getBag()->insertFirst(item);
            }

            else if (knight->getId() <= 0)
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

string BaseBag::toString() const
{
    string s("");
    int arr[sizeBag];
    BaseItem *temp = head;
    int iter = 0;
    while (temp != nullptr)
    {
        arr[iter] = temp->itemType;

        temp = temp->next;
        iter += 1;
    }

    s += "Bag[count=" + to_string(sizeBag) + ";";
    for (int i = 0; i < sizeBag; i++)
    {
        if (arr[i] == phoenixDownI)
        {
            s += "PhoenixI";
        }
        else if (arr[i] == phoenixDownII)
        {
            s += "PhoenixII";
        }
        else if (arr[i] == phoenixDownIII)
        {
            s += "PhoenixIII";
        }
        else if (arr[i] == phoenixDownIV)
        {
            s += "PhoenixIV";
        }
        else if (arr[i] == ANTIDOTE)
        {
            s += "Antidote";
        }
        if (i + 1 != sizeBag)
        {
            s += ",";
        }
    }
    s += "]";
    return s;
}

void BaseBag::insertBag(ItemType item)
{
    if (item == phoenixDownI)
    {
        PhoenixDownI *object = new PhoenixDownI();
        object->next = head;
        head = object;
        sizeBag += 1;
    }
    else if (item == phoenixDownII)
    {
        PhoenixDownII *object = new PhoenixDownII();
        object->next = head;
        head = object;
        sizeBag += 1;
    }
    else if (item == phoenixDownIII)
    {
        PhoenixDownII *object = new PhoenixDownII();
        object->next = head;
        head = object;
        sizeBag += 1;
    }
    else if (item == phoenixDownIV)
    {
        PhoenixDownIV *object = new PhoenixDownIV();
        object->next = head;
        head = object;
        sizeBag += 1;
    }
    else
    {
        Antidote *object = new Antidote();
        object->next = head;
        head = object;
        sizeBag += 1;
    }
}

BaseItem *BaseBag::get(ItemType itemType)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (itemType == FirstPhoenixDown)
    {
        BaseItem *temp = head;
        while (temp != nullptr)
        {
            if (temp->itemType == phoenixDownI || temp->itemType == phoenixDownII || temp->itemType == phoenixDownIII || temp->itemType == phoenixDownIV)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    BaseItem *temp = head;
    while (temp != nullptr)
    {
        if (temp->itemType == itemType)
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void BaseBag::swapBag(BaseItem *item)
{
    if (item == nullptr)
    {
        return;
    }
    ItemType temp = item->itemType;
    item->itemType = head->itemType;
    head->itemType = temp;
}

void BaseBag::deleteBag()
{
    if (head == nullptr)
    {
        return;
    }
    BaseItem *temp = head;
    head = head->next;
    delete temp;
}

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */

static BaseKnight *create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
{
    if (maxhp > 999)
    {
        maxhp = 999;
    }

    if (level > 10)
    {
        level = 10;
    }

    if (phoenixdownI > 5)
    {
        phoenixdownI = 5;
    }

    if (gil > 999)
    {
        gil = 999;
    }

    if (antidote > 5)
    {
        antidote = 5;
    }

    BaseKnight *newKnight;

    KnightType typ = makeKnightType(maxhp);
    if (typ == DRAGON)
    {
        newKnight = new DragonKnight();
    }

    else if (typ == LANCELOT)
    {
        newKnight = new LancelotKnight();
    }

    else if (typ == PALADIN)
    {
        newKnight = new PaladinKnight();
    }

    else
    {
        newKnight = new NormalKnight();
    }

    newKnight->setId(id);
    newKnight->setHp(maxhp);
    newKnight->setMaxhp(maxhp);
    newKnight->setLevel(level);
    newKnight->setGil(gil);
    newKnight->setKnightType(typ);
    newKnight->set2();
    newKnight->setBag(phoenixDownI, phoenixdownI);
    if (typ != DRAGON)
    {
        newKnight->setBag(ANTIDOTE, antidote);
    }
    newKnight->getBag()->knight = newKnight;
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
        if (size >= 5)
        {
            size = 5;
        }

        for (int i = 0; i < size; i++)
        {
            if (item == phoenixDownI)
            {
                bag->insertBag(item);
            }

            else if (item == phoenixDownII)
            {
                bag->insertBag(item);
            }

            else if (item == phoenixDownIII)
            {
                bag->insertBag(item);
            }

            else if (item == phoenixDownIV)
            {
                bag->insertBag(item);
            }

            else if (item == ANTIDOTE)
            {
                bag->insertBag(item);
            }
        }
    }
}

/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */

ArmyKnights::~ArmyKnights()
{
    // int len = sizeArmy;
    // for (int i = 0; i < len; i++)
    // {
    //     BaseKnight *lastKnight = this->lastKnight();
    //     sizeArmy -= 1;
    //     free(lastKnight);
    // }
    // if (sizeArmy > 0)
    // {
    //     delete arrArmy;
    // }
    // for (int i = 0; i < sizeArmy; i++) 
    // {
    //     delete (arrArmy + i);
    // }
    delete[] arrArmy;
}

void ArmyKnights::printInfo() const
{
    // cout << "No. knights: " << this->count();
    // if (this->count() > 0)
    // {
    //     BaseKnight *lknight = lastKnight(); // last knight
    //     cout << ";" << lknight->toString();
    // }
    // cout << ";PaladinShield:" << this->hasPaladinShield()
    //      << ";LancelotSpear:" << this->hasLancelotSpear()
    //      << ";GuinevereHair:" << this->hasGuinevereHair()
    //      << ";ExcaliburSword:" << this->hasExcaliburSword()
    //      << endl
    //      << string(50, '-') << endl;
    string s = "No. knights: " + to_string(this->count());
    if (this->count() > 0)
    {
        BaseKnight *lknight = lastKnight();
        s += ";" + lknight->toString();
    }
    s += ";PaladinShield:" + to_string(this->hasPaladinShield());
    s += ";LancelotSpear:" + to_string(this->hasLancelotSpear());
    s += ";GuinevereHair:" + to_string(this->hasGuinevereHair());
    s += ";ExcaliburSword:" + to_string(this->hasExcaliburSword());
    s += "\n";
    s += string(50, '-') + "\n";
    output += s;
    cout << s;
}

void ArmyKnights::printResult(bool win) const
{
    cout << (win ? "WIN" : "LOSE") << endl;
}

int ArmyKnights::count() const
{
    return sizeArmy;
}

BaseKnight *ArmyKnights::lastKnight() const {
    if (sizeArmy == 0) {
        return nullptr;  
    } 
    
    else 
    {
        return &arrArmy[sizeArmy - 1];
    }
}

bool ArmyKnights::fight(BaseOpponent *opponent)
{
    if (sizeArmy == 0)
    {
        return false;
    }

    BaseKnight *lastKnight = this->lastKnight();

    int levelOppo = opponent->levelO;
    int baseDam = opponent->baseDamage;
    int evenNum = opponent->eventNum;

    int gil = lastKnight->getGil();
    int level = lastKnight->getLevel();
    int hp = lastKnight->getHp();
    int maxhp = lastKnight->getMaxhp();
    int typ = lastKnight->getKnightType();

    if (evenNum >= 1 && evenNum <= 5)
    {
        // cout << "level: " << level << endl;
        // cout << "levelOppo: " << levelOppo << endl;
        if (level >= levelOppo || typ == LANCELOT || typ == PALADIN)
        {
            gil += opponent->gilIfWin;
            if (gil > 999)
            {
                gil = 999;
            }
            lastKnight->setGil(gil);
            return true;
        }

        hp = hp - baseDam * (levelOppo - level);
        // cout << hp << endl;
        lastKnight->setHp(hp);
        // if (hp <= 0)
        // {
        //     // cout << "co di zo day" << endl;
        //     BaseItem * temp = lastKnight->getBag()->get(FirstPhoenixDown);
        //     while (temp != nullptr)
        //     {
        //         // cout << "tim duoc phoenix\n";
        //         lastKnight->getBag()->swapBag(temp);
        //         temp->use(lastKnight);
        //         int hpnew = lastKnight->getHp();
        //         // cout << hpnew << endl;
        //         if (hpnew > 0)
        //         {
        //             return true;
        //         }
        //         temp = lastKnight->getBag()->get(FirstPhoenixDown);
        //     }

        //     if (gil >= 100)
        //     {
        //         gil -= 100;
        //         hp = maxhp / 2;
        //         lastKnight -> setGil(gil);
        //         lastKnight -> setHp(hp);
        //         return true;
        //     }

        //     delete lastKnight;
        //     sizeArmy -= 1;
        // }
        if (hp <= 0)
        {
            if (!BleedToDeath())
            {
                return false;
            }
        }

        else
        {
            searchAndUse();
        }
        return true;
    }

    else if (evenNum == 6)
    {
        if (level >= levelOppo)
        {
            level += 1;
            if (level >= 10)
            {
                level = 10;
            }
            lastKnight->setLevel(level);
            return true;
        }

        if (typ == DRAGON)
        {
            return true;
        }

        if (lastKnight->getBag()->get(ANTIDOTE) != nullptr)
        {
            lastKnight->getBag()->swapBag(lastKnight->getBag()->get(ANTIDOTE));
            lastKnight->getBag()->deleteBag();
            lastKnight->getBag()->sizeBag -= 1;
            return true;
        }

        // thua o day ne
        BaseItem *temp = lastKnight->getBag()->head;
        if (lastKnight->getBag()->sizeBag <= 3)
        {
            while (temp != NULL)
            {
                BaseItem *nest = temp->next;
                delete temp;
                temp = nest;
            }
            lastKnight->getBag()->sizeBag = 0;
            lastKnight->getBag()->head = NULL;
        }

        else
        {
            // for (int i = 0; i < lastKnight->getBag()->sizeBag - 3; i++)
            // {
            //     temp = temp->next;
            // }

            // while (temp != NULL)
            // {
            //     BaseItem *nest = temp->next;
            //     delete temp;
            //     temp = nest;
            // }
            for (int i = 0; i < 3; i++)
            {
                temp = lastKnight->getBag()->head->next;
                delete lastKnight->getBag()->head;
                lastKnight->getBag()->head = temp;
            }

            lastKnight->getBag()->sizeBag -= 3;
        }

        hp -= 10;
        lastKnight->setHp(hp);
        if (hp <= 0)
        {
            if (!BleedToDeath())
            {
                return false;
            }
        }
        else
        {
            searchAndUse();
        }
        return true;
    }

    else if (evenNum == 7)
    {
        if (level >= levelOppo)
        {
            gil *= 2;
            if (gil > 999)
            {
                int remain = gil - 999;
                gil = 999;
                lastKnight->setGil(gil);

                for (int i = 0; i < sizeArmy - 1; i++)
                {
                    if (remain <= 0)
                    {
                        break;
                    }
                    BaseKnight *beforeKnight = lastKnight - (i + 1);
                    int thisGil = beforeKnight->getGil();
                    thisGil += remain;
                    if (thisGil <= 999)
                    {
                        beforeKnight->setGil(thisGil);
                        break;
                    }

                    if (thisGil > 999)
                    {
                        remain = thisGil - 999;
                        thisGil = 999;
                        beforeKnight->setGil(thisGil);
                    }
                }
            }
            lastKnight->setGil(gil);
            return true;
        }

        else
        {
            if (typ == PALADIN)
            {
                return true;
            }
            gil /= 2;
            lastKnight->setGil(gil);
            return true;
        }
    }

    else if (evenNum == 8)
    {
        if (typ == PALADIN)
        {
            if (hp < maxhp / 3)
            {
                hp += maxhp / 5;
                if (hp > 999)
                {
                    hp = 999;
                }
                lastKnight->setHp(hp);
            }
            return true;
        }

        if (gil < 50)
        {
            return true;
        }

        if (hp < maxhp / 3)
        {
            gil -= 50;
            hp += maxhp / 5;
            if (hp > 999)
            {
                hp = 999;
            }
            lastKnight->setHp(hp);
            lastKnight->setGil(gil);
            return true;
        }
        return true;
    }

    else if (evenNum == 9)
    {
        lastKnight->setHp(maxhp);
        return true;
    }

    else if (evenNum == 10)
    {
        if ((level == 10 && hp == maxhp) || (typ == DRAGON))
        {
            level = 10;
            gil = 999;
            lastKnight->setLevel(level);
            lastKnight->setGil(gil);
            return true;
        }

        else
        {
            hp = 0;
            lastKnight->setHp(hp);
            if (hp <= 0)
            {
                if (!BleedToDeath())
                {
                    return false;
                }
            }
            else
            {
                searchAndUse();
            }
            return false;
        }
    }

    else if (evenNum == 11)
    {
        if (level == 10 || (typ == PALADIN && level >= 8))
        {
            PaladinShield = true;
            return true;
        }

        else
        {
            hp = 0;
            lastKnight->setHp(hp);
            if (hp <= 0)
            {
                if (!BleedToDeath())
                {
                    return false;
                }
            }
            else
            {
                searchAndUse();
            }
            return false;
        }
    }

    else if (evenNum == 99)
    {

        if (hasExcaliburSword())
        {
            return true;
        }

        // else if (hasPaladinShield() && hasLancelotSpear() && hasGuinevereHair())
        // {
        //     int dam = 0;
        //     if (typ != NORMAL)
        //     {
        //         dam += hp * level * lastKnight->knightBaseDamage;
        //         if (dam < 5000)
        //         {
        //             delete lastKnight;
        //             sizeArmy -= 1;
        //         }
        //     }

        //     int len = sizeArmy - 1;
        //     for (int i = 0; i < len; i++)
        //     {
        //         BaseKnight *beforeKnight = lastKnight - (i + 1);
        //         if (beforeKnight->getKnightType() != NORMAL)
        //         {
        //             dam += beforeKnight->getHp() * beforeKnight->getLevel() * beforeKnight->knightBaseDamage;
        //             if (dam < 5000)
        //             {
        //                 delete beforeKnight;
        //                 sizeArmy -= 1;
        //             }
        //             else
        //             {
        //                 return true;
        //             }
        //         }
        //     }
        //     // delete[] arrArmy;
        //     sizeArmy = 0;
        //     return false;
        // }

        else if (hasPaladinShield() && hasLancelotSpear() && hasGuinevereHair())
        {
            int dam = 0;
            int len = sizeArmy - 1;
            
            for (int i = len; i >= 0; i--)
            {         
                //  cout << i << " ";

                BaseKnight * beforeKnight = &arrArmy[i];  
                // cout << "HP = " << beforeKnight->getHp()<< " ";    
                KnightType newtyp = beforeKnight->getKnightType();
                if (newtyp == NORMAL)
                {
                    // cout << "SKIP" << endl;
                    continue;
                }
                dam += beforeKnight->getHp() * beforeKnight->getLevel() * beforeKnight->knightBaseDamage;
                // cout << dam << endl;

                if (dam < 5000)
                {
                    BaseKnight * newArrArmy = new BaseKnight[sizeArmy - 1];

                    for (int j = 0; j < sizeArmy - 1; j++)
                    {
                        if (j < i)
                        {
                            newArrArmy[j] = arrArmy[j];
                        }

                        else 
                        {
                            newArrArmy[j] = arrArmy[j + 1];
                        }
                    }
                    delete[] arrArmy;
                    sizeArmy -= 1;
                    arrArmy = newArrArmy;
                }
                else 
                {
                    // for (int i = 0; i < sizeArmy; i++)
                    // {
                    //     cout << (arrArmy + i) -> toString() << endl;;
                    // }
                    return true;
                }
                
            }
            sizeArmy = 0;
            return false;
        }


        else
        {
            sizeArmy = 0;
            return false;
        }
    }

    return false;
}

bool ArmyKnights::adventure(Events *events)
{
    bool Omega = false, HadesBool = false;
    int len = events->count();
    for (int i = 0; i < len; i++)
    {
        int thisEvent = events->arrEvents[i];

        if (thisEvent >= 1 && thisEvent <= 5)
        {
            int levelO = (i + thisEvent) % 10 + 1;

            if (thisEvent == 1)
            {
                MadBear *opponent = new MadBear(levelO);
                fight(opponent);
                delete opponent;
            }
            else if (thisEvent == 2)
            {
                Bandit *opponent = new Bandit(levelO);
                fight(opponent);
                delete opponent;
            }
            else if (thisEvent == 3)
            {
                LordLupin *opponent = new LordLupin(levelO);
                fight(opponent);
                delete opponent;
            }
            else if (thisEvent == 4)
            {
                Elf *opponent = new Elf(levelO);
                fight(opponent);
                delete opponent;
            }
            else if (thisEvent == 5)
            {
                Troll *opponent = new Troll(levelO);
                fight(opponent);
                delete opponent;
            }
        }

        else if (thisEvent == 6)
        {
            int levelO = (i + thisEvent) % 10 + 1;
            Tornbery *opponent = new Tornbery(levelO);
            fight(opponent);
            delete opponent;
        }

        else if (thisEvent == 7)
        {
            int levelO = (i + thisEvent) % 10 + 1;
            QueenOfCards *opponent = new QueenOfCards(levelO);
            fight(opponent);
            delete opponent;
        }

        else if (thisEvent == 8)
        {
            NinaDeRings *opponent = new NinaDeRings();
            fight(opponent);
            delete opponent;
        }

        else if (thisEvent == 9)
        {
            DurianGarden *opponent = new DurianGarden();
            fight(opponent);
            delete opponent;
        }

        else if (thisEvent == 10)
        {
            if (Omega == false)
            {
                OmegaWeapon *opponent = new OmegaWeapon();
                if (fight(opponent))
                {
                    Omega = true; 
                }
                delete opponent;
            }
        }

        else if (thisEvent == 11)
        {
            if (HadesBool == false)
            {
                Hades *opponent = new Hades();
                if (fight(opponent))
                {
                    HadesBool = true;
                }
                delete opponent;
            }
        }

        else if (thisEvent == 95)
        {
            PaladinShield = true;
        }

        else if (thisEvent == 96)
        {
            LancelotSpear = true;
        }

        else if (thisEvent == 97)
        {
            GuinevereHair = true;
        }

        else if (thisEvent == 98)
        {
            if (hasPaladinShield() && hasLancelotSpear() && hasGuinevereHair())
            {
                ExcaliburSword = true;
            }
        }

        else if (thisEvent == 99)
        {
            Ultimecia *opponent = new Ultimecia();
            fight(opponent);
            delete opponent;
        }

        else if (thisEvent == 112)
        {
            PhoenixDownII *object = new PhoenixDownII();
            BaseKnight *lastKnight = this->lastKnight();
            lastKnight->getBag()->insertFirst(object);
        }

        else if (thisEvent == 113)
        {
            PhoenixDownIII *object = new PhoenixDownIII();
            BaseKnight *lastKnight = this->lastKnight();
            lastKnight->getBag()->insertFirst(object);
        }

        else if (thisEvent == 114)
        {
            PhoenixDownIV *object = new PhoenixDownIV();
            BaseKnight *lastKnight = this->lastKnight();
            lastKnight->getBag()->insertFirst(object);
        }

        printInfo();

        if (sizeArmy <= 0)
        {
            return false;
        }
    }
    return true;
}

/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class Events * * */

Events::~Events()
{
    delete[] arrEvents;
}

int Events::count() const
{
    return sizeEvents;
}

int Events::get(int i) const
{
    return arrEvents[i];
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
    bool win = true;
    if (!armyKnights->adventure(events))
    {
        win = false;
    }
    armyKnights->printResult(win);

    // if (win == true)
    // {
    //     output += "WIN";
    // }

    // else
    // {
    //     output += "LOSE";
    // }

    // ofstream outfile("output.txt");
    // if (outfile.is_open())
    // {
    //     outfile << output;
    //     outfile.close();
    // }
    // else
    // {
    //     std::cout << "Failed to open file." << std::endl;
    // }
}

/* * * END implementation of class KnightAdventure * * */

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

    // sizeEvents = 6;
    // arrEvents = new int[sizeEvents];
    // arrEvents[0] = 95;
    // arrEvents[1] = 95;
    // arrEvents[2] = 96;
    // arrEvents[3] = 97;
    // arrEvents[4] = 98;
    // arrEvents[5] = 99;
}

ArmyKnights::ArmyKnights(const string &file_armyknights)
{

    PaladinShield = false;
    LancelotSpear = false;
    GuinevereHair = false;
    ExcaliburSword = false;

    ifstream fp;
    fp.open(file_armyknights);
    fp >> sizeArmy;
    arrArmy = new BaseKnight [sizeArmy];
    int hp, level, phoenixdownI, gil, antidote;
    for (int i = 0; i < sizeArmy; i++)
    {
        fp >> hp >> level >> phoenixdownI >> gil >> antidote;
        BaseKnight * temp = create(i + 1, hp, level, gil, antidote, phoenixdownI);
        arrArmy[i] = *temp;
        delete temp;
    }
    fp.close();

    // sizeArmy = 1;
    // arrArmy = new BaseKnight[sizeArmy];
    // arrArmy[0] = *create(1, 601, 7, 99, 0, 0);
}