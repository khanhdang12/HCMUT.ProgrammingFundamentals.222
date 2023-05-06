

enum Weapon
{
    Sword,
    Bow,
    Spear,
    ShieldSword,
    HeavyAxe,
    Dagger
};


class gladiator
{
    Weapon weapon;
    double power;
    double learningRate;

public:
    gladiator(){};
    gladiator(Weapon a, double b, double c)
    {
        weapon = a;
        power = b;
        learningRate = c;
    }
    void winAgainst(gladiator b)
    {
        power += b.power * learningRate;
    }
    double getPow()
    {
        return power;
    }
    Weapon getWeapon()
    {
        return weapon;
    }
};
class colosseum
{
    int count;
    gladiator *Glads;

public:
    colosseum()
    {
        count = 0;
        Glads = new gladiator[100];
    }
    ~colosseum()
    {
        delete[] Glads;
    }
    void addGlad(gladiator a)
    {
        Glads[count] = a;
        count += 1;
    }
    void addGlad(gladiator *a, int n)
    {
        for (int i = 0; i < n; i++)
        {
            Glads[count] = a[i];
            count += 1;
        }
    }
    void startFight(int a, int b)
    {
        gladiator &glad1 = Glads[a];
        gladiator &glad2 = Glads[b];

        double glad1Power = glad1.getPow();
        double glad2Power = glad2.getPow();

        Weapon weap1 = glad1.getWeapon();
        Weapon weap2 = glad2.getWeapon();

        string getChar[6] = {"Sword", "Bow", "Spear", "ShieldSword", "HeavyAxe", "Dagger"};

        cout << "Today fight is between:\n";
        cout << "the Gladiator " << a << " a " << getChar[glad1.getWeapon()] << " user with the power of " << glad1Power << endl;
        cout << "and the Gladiator " << b << " a " << getChar[glad2.getWeapon()] << " user with the power of " << glad2Power << endl;

        if (weap1 == Sword && weap2 == Dagger)
        {
            glad1Power *= 1.5;
        }

        else if (weap1 == Dagger && weap2 == Sword)
        {
            glad1Power *= 1.5;
        }

        else if (weap1 - weap2 == 1)
        {
            glad1Power *= 1.5;
        }

        else if (weap2 - weap1 == 1)
        {
            glad2Power *= 1.5;
        }

        if (glad1Power > glad2Power)
        {
            cout << "After a tenacious fight the Gladiator " << a << " Won the match\n";
            glad1.winAgainst(glad2);

            gladiator *newGlads = new gladiator[count - 1];
            for (int i = 0; i < count - 1; i++)
            {
                if (i < b)
                {
                    newGlads[i] = Glads[i];
                }

                else
                {
                    newGlads[i] = Glads[i + 1];
                }
            }
            delete[] Glads;
            Glads = newGlads;
            count -= 1;
            return;
        }

        else if (glad2Power > glad1Power)
        {
            cout << "After a tenacious fight the Gladiator " << b << " Won the match\n";
            glad2.winAgainst(glad1);
            gladiator *newGlads = new gladiator[count - 1];
            for (int i = 0; i < count - 1; i++)
            {
                if (i < a)
                {
                    newGlads[i] = Glads[i];
                }

                else
                {
                    newGlads[i] = Glads[i + 1];
                }
            }
            delete[] Glads;
            Glads = newGlads;
            count -= 1;
            return;
        }

        cout << "After a cruel fight both fighters lost their lives" << endl;

        if (a > b)
        {
            int temp = b;
            b = a;
            a = temp;
        }

        for (int i = 0; i < count - 1; i++)
        {
            if (i >= a)
            {
                Glads[i] = Glads[i + 1];
            }
        }

        for (int i = 0; i < count - 2; i++)
        {
            if (i >= b -1)
            {
                Glads[i] = Glads[i + 1];
            }
        }  
        count -= 2;
        return;
    } 
};

