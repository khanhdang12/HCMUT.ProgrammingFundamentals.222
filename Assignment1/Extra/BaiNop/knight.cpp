#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue)
{
    cout << "HP=" << HP
         << ", level=" << level
         << ", remedy=" << remedy
         << ", maidenkiss=" << maidenkiss
         << ", phoenixdown=" << phoenixdown
         << ", rescue=" << rescue << endl;
}

void tinytiny(int &HP, int &remedy, int &tinyflag, int &tiny)
{
    if (remedy >= 1)
    {
        remedy -= 1;
    }

    else
    {
        tinyflag = 1;
        tiny = 4;
        if (HP < 5)
        {
            HP = 1;
        }
        else
        {
            HP = HP / 5;
        }
    }
}

void outtiny(int &HP, int &maxHP, int &tinyflag, int &tiny)
{
    HP = HP * 5;
    if (HP > maxHP)
    {
        HP = maxHP;
    }
    tinyflag = 0;
    tiny = 0;
}

void frogfrog(int &level, int &maidenkiss, int &frogflag, int &frog, int &froglevel)
{
    if (maidenkiss >= 1)
    {
        maidenkiss -= 1;
    }

    else
    {
        froglevel = level;
        level = 1;
        frogflag = 1;
        frog = 4;
    }
}

void outfrog(int &level, int &frogflag, int &frog, int &froglevel)
{
    level = froglevel;
    froglevel = 1;
    frogflag = 0;
    frog = 0;
}

void dieCheck(int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue, int &maxHP, int &tinyflag, int &tiny, int &frogflag, int &frog, int &froglevel)
{
    if (HP <= 0)
    {
        if (phoenixdown == 0)
        {
            rescue = 0;
        }

        else if (phoenixdown >= 1)
        {
            phoenixdown -= 1;
            if (tinyflag == 1)
            {
                outtiny(HP, maxHP, tinyflag, tiny);
            }
            else if (frogflag == 1)
            {
                outfrog(level, frogflag, frog, froglevel);
            }
            HP = maxHP;
        }
    }
}

void dieCheckMush(int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue, int &maxHP, int &tinyflag, int &tiny, int &frogflag, int &frog, int &froglevel, bool &flag)
{
    if (HP <= 0)
    {
        if (phoenixdown == 0)
        {
            rescue = 0;
            flag = true;
        }

        else if (phoenixdown >= 1)
        {
            phoenixdown -= 1;
            if (tinyflag == 1)
            {
                outtiny(HP, maxHP, tinyflag, tiny);
            }
            else if (frogflag == 1)
            {
                outfrog(level, frogflag, frog, froglevel);
            }
            HP = maxHP;
        }
    }
}

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

void theline(string file_input, string &str)
{
    ifstream fp;
    fp.open(file_input);
    getline(fp, str);
    getline(fp, str);
    getline(fp, str);
    fp.close();
}

void mush(string file_mush_ghost, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue, int &maxHP, int &tinyflag, int &tiny, int &frogflag, int &frog, int &froglevel, int &event)
{
    ostringstream temp;
    temp << event;
    string eventstring = temp.str();
    int len = eventstring.length();

    ifstream fp;
    fp.open(file_mush_ghost);
    string line1, line2;
    getline(fp, line1);
    getline(fp, line2);

    int lenline1 = stoi(line1), lenline2 = line2.length(), intarr[lenline1], count = 0;
    string strarr[lenline1], temp2 = "";

    for (int i = 0; i < lenline2; i++)
    {
        if (line2[i] == ',')
        {
            strarr[count] = temp2;
            count += 1;
            temp2 = "";
        }

        else
        {
            temp2 += line2[i];
        }
    }
    strarr[count] = temp2;

    for (int i = 0; i < lenline1; i++)
    {
        intarr[i] = stoi(strarr[i]);
    }

    bool flag = false;
    for (int i = 2; i < len; i++)
    {
        if (eventstring[i] == '1')
        {
            int maxi = 0, mini = 0, max = -9999, min = 9999;

            for (int j = 0; j < lenline1; j++)
            {
                if (intarr[j] >= max)
                {
                    max = intarr[j];
                    maxi = j;
                }

                if (intarr[j] <= min)
                {
                    min = intarr[j];
                    mini = j;
                }
            }
            HP = HP - (maxi + mini);
        }

        else if (eventstring[i] == '2')
        {
            int mtx = -2, mti = -3;
            bool isMountain = true;

            for (int i = 0; i < lenline1 - 1; i++) // 0 is peak
            {
                if (intarr[i + 1] >= intarr[i])
                {
                    isMountain = false;
                    break;
                }
            }

            if (!isMountain)
            {
                isMountain = true;
                for (int i = 0; i < lenline1 - 1; i++) // n is peak
                {
                    if (intarr[i + 1] <= intarr[i])
                    {
                        isMountain = false;
                        break;
                    }
                }

                if (!isMountain)
                {
                    isMountain = true;
                    for (int i = 1; i < lenline1 - 1; i++) // peak is middle
                    {
                        if (intarr[i] > intarr[i - 1] && intarr[i] > intarr[i + 1])
                        {
                            mtx = intarr[i];
                            mti = i;
                            break;
                        }
                    }

                    for (int i = 0; i < mti; i++)
                    {
                        if (intarr[i] >= intarr[i + 1])
                        {
                            isMountain = false;
                            break;
                        }
                    }

                    for (int i = mti; i < lenline1 - 1; i++)
                    {
                        if (intarr[i] <= intarr[i + 1])
                        {
                            isMountain = false;
                            break;
                        }
                    }

                    if (!isMountain)
                    {
                        mtx = -2;
                        mti = -3;
                    }
                }

                else
                {
                    mtx = intarr[lenline1 - 1];
                    mti = lenline1 - 1;
                }
            }

            else
            {
                mtx = intarr[0];
                mti = 0;
            }
            HP = HP - (mtx + mti);
        }

        else if (eventstring[i] == '3')
        {
            int arr[lenline1];
            for (int i = 0; i < lenline1; i++)
            {
                arr[i] = intarr[i];
            }

            for (int i = 0; i < lenline1; i++)
            {
                if (arr[i] < 0)
                {
                    arr[i] = -arr[i];
                }
                arr[i] = (17 * arr[i] + 9) % 257;
            }

            int maxi2 = 0, mini2 = 0, max = -9999, min = 9999;
            for (int j = 0; j < lenline1; j++)
            {
                if (arr[j] > max)
                {
                    max = arr[j];
                    maxi2 = j;
                }

                if (arr[j] < min)
                {
                    min = arr[j];
                    mini2 = j;
                }
            }
            HP = HP - (maxi2 + mini2);
        }

        else if (eventstring[i] == '4')
        {
            int max2_3x = -5, max2_3i = -7;

            int arr[lenline1];
            for (int j = 0; j < lenline1; j++)
            {
                arr[j] = intarr[j];
            }

            for (int j = 0; j < lenline1; j++)
            {
                if (arr[j] < 0)
                {
                    arr[j] = -arr[j];
                }
                arr[j] = (17 * arr[j] + 9) % 257;
            }

            int max = -9999;
            for (int j = 0; j < 3; j++)
            {
                if (arr[j] > max)
                {
                    max = arr[j];
                }
            }

            for (int j = 0; j < 3; j++)
            {
                if (arr[j] != max)
                {
                    if (arr[j] > max2_3x)
                    {
                        max2_3x = arr[j];
                        max2_3i = j;
                    }
                }
            }

            if (lenline1 < 3)
            {
                max2_3x = -5;
                max2_3i = -7;
            }
            HP = HP - (max2_3x + max2_3i);
        }

        dieCheckMush(HP, level, remedy, maidenkiss, phoenixdown, rescue, maxHP, tinyflag, tiny, frogflag, frog, froglevel, flag);
        if (HP > maxHP)
        {
            HP = maxHP;
        }
        if (flag == true)
        {
            break;
        }
    }
    fp.close();
}

void numOfEvent(string file_input, int &numEvent)
{
    ifstream fp;
    fp.open(file_input);
    int k;
    while (fp >> k)
    {
        numEvent++;
    }
    numEvent -= 5;
    fp.close();
}

void asclepiusCall(string file_name, int &remedy, int &maidenkiss, int &phoenixdown, bool &asclepius)
{
    if (asclepius == false)
    {
        asclepius = true;
        ifstream fp(file_name);
        int r1, c1;
        fp >> r1;
        fp >> c1;

        int arr[r1][c1];
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                fp >> arr[i][j];
            }
        }

        for (int i = 0; i < r1; i++)
        {
            int flag = 0;
            for (int j = 0; j < c1; j++)
            {
                if (flag == 3)
                {
                    break;
                }

                else
                {
                    if (arr[i][j] == 16)
                    {
                        remedy += 1;
                        flag += 1;
                    }
                    else if (arr[i][j] == 17)
                    {
                        maidenkiss += 1;
                        flag += 1;
                    }
                    else if (arr[i][j] == 18)
                    {
                        phoenixdown += 1;
                        flag += 1;
                    }
                }
            }
        }
        if (remedy > 99)
        {
            remedy = 99;
        }
        if (maidenkiss > 99)
        {
            maidenkiss = 99;
        }
        if (phoenixdown > 99)
        {
            phoenixdown = 99;
        }
        fp.close();
    }
}

void merlinCall(string file_input, int &HP, int &maxHP, bool &merlin)
{
    if (merlin == false)
    {
        merlin = true;
        ifstream fp(file_input);
        int n9;
        string str, str1 = "Merlin", str2 = "merlin";
        size_t found;
        fp >> n9;

        while (fp >> str)
        {
            found = str.find(str1);
            if (found != string::npos)
            {
                HP += 3;
            }

            else
            {
                found = str.find(str2);
                if (found != string::npos)
                {
                    HP += 3;
                }

                else
                {
                    bool w1 = false, w2 = false, w3 = false, w4 = false, w5 = false, w6 = false;
                    for (int i = 0; i < str.length(); i++)
                    {
                        if (str[i] == 'M' || str[i] == 'm')
                        {
                            w1 = true;
                        }
                        else if (str[i] == 'E' || str[i] == 'e')
                        {
                            w2 = true;
                        }
                        else if (str[i] == 'R' || str[i] == 'r')
                        {
                            w3 = true;
                        }
                        else if (str[i] == 'L' || str[i] == 'l')
                        {
                            w4 = true;
                        }
                        else if (str[i] == 'I' || str[i] == 'i')
                        {
                            w5 = true;
                        }
                        else if (str[i] == 'N' || str[i] == 'n')
                        {
                            w6 = true;
                        }
                    }
                    if (w1 == true && w2 == true && w3 == true && w4 == true && w5 == true && w6 == true)
                    {
                        HP += 2;
                    }
                }
            }
            if (HP > maxHP)
            {
                HP = maxHP;
            }
        }
        fp.close();
    }
}

void adventureToKoopa(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue)
{
    int numEvent = 0;
    numOfEvent(file_input, numEvent);

    string str, strtemp = "", strarr[3];
    int strcount = 0;
    theline(file_input, str);

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ',')
        {
            strarr[strcount] = strtemp;
            strcount += 1;
            strtemp = "";
        }
        else
        {
            strtemp += str[i];
        }
    }
    strarr[strcount] = strtemp;

    ifstream fp;
    fp.open(file_input);
    fp >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
    int maxHP = HP, event, i = 1, tinyflag = 0, tiny = 0, frogflag = 0, frog = 0, froglevel = 1, arthur = 0, lancelot = 0;
    rescue = -1;
    bool asclepius = false, merlin = false;

    if (HP == 999)
    {
        arthur = 1;
    }

    else if (isPrime(HP))
    {
        lancelot = 1;
    }

    while (fp >> event)
    {
        int b = i % 10, levelO = i > 6 ? (b > 5 ? b : 5) : b;

        if (event == 0)
        {
            rescue = 1;
        }

        else if (event >= 1 && event <= 5)
        {
            if (level > levelO || arthur == 1 || lancelot == 1)
            {
                level += 1;
                if (level > 10)
                {
                    level = 10;
                }
            }

            else if (level < levelO)
            {
                float damage, baseDamage;
                if (event == 1)
                {
                    baseDamage = 1;
                }
                else if (event == 2)
                {
                    baseDamage = 1.5;
                }
                else if (event == 3)
                {
                    baseDamage = 4.5;
                }
                else if (event == 4)
                {
                    baseDamage = 7.5;
                }
                else if (event == 5)
                {
                    baseDamage = 9.5;
                }

                damage = baseDamage * levelO * 10;
                HP = HP - damage;
                dieCheck(HP, level, remedy, maidenkiss, phoenixdown, rescue, maxHP, tinyflag, tiny, frogflag, frog, froglevel);
            }
        }

        else if (event == 6)
        {
            if (tinyflag != 1 && frogflag != 1)
            {
                if (level > levelO || arthur == 1 || lancelot == 1)
                {
                    level += 2;
                    if (level > 10)
                    {
                        level = 10;
                    }
                }

                else if (level < levelO)
                {
                    tinytiny(HP, remedy, tinyflag, tiny);
                }
            }
        }

        else if (event == 7)
        {
            if (tinyflag != 1 && frogflag != 1)
            {
                if (level > levelO || arthur == 1 || lancelot == 1)
                {
                    level += 2;
                    if (level > 10)
                    {
                        level = 10;
                    }
                }

                else if (level < levelO)
                {
                    frogfrog(level, maidenkiss, frogflag, frog, froglevel);
                }
            }
        }

        else if (event == 11)
        {
            int mushmario = 99, s1 = 0;
            for (int n1 = ((level + phoenixdown) % 5 + 1) * 3; n1 > 0; n1 -= 1)
            {
                s1 += mushmario;
                mushmario -= 2;
            }

            HP = HP + (s1 % 100);

            int temp = 0;
            while (1)
            {
                if (isPrime(temp) && temp > HP)
                {
                    HP = temp;
                    break;
                }
                temp++;
            }

            if (HP > maxHP)
            {
                HP = maxHP;
            }
        }

        else if (event == 12)
        {
            if (HP > 1)
            {
                int i = 1, j = 1, fibo = 0, temp = 1;
                while (fibo < HP)
                {
                    fibo = i + j;
                    temp = i;
                    i = j;
                    j = fibo;
                }
                HP = fibo - temp;
            }
        }

        else if (event > 100) // event 13;
        {
            mush(strarr[0], HP, level, remedy, maidenkiss, phoenixdown, rescue, maxHP, tinyflag, tiny, frogflag, frog, froglevel, event);
        }

        else if (event == 15)
        {
            remedy += 1;
            if (remedy > 99)
            {
                remedy = 99;
            }
        }

        else if (event == 16)
        {
            maidenkiss += 1;
            if (maidenkiss > 99)
            {
                maidenkiss = 99;
            }
        }

        else if (event == 17)
        {
            phoenixdown += 1;
            if (phoenixdown > 99)
            {
                phoenixdown = 99;
            }
        }

        else if (event == 18)
        {
            merlinCall(strarr[2], HP, maxHP, merlin);
        }

        else if (event == 19)
        {
            asclepiusCall(strarr[1], remedy, maidenkiss, phoenixdown, asclepius);
        }

        else if (event == 99)
        {
            if (arthur == 1 || (lancelot == 1 && level >= 8) || level == 10)
            {
                level = 10;
            }
            else
            {
                rescue = 0;
            }
        }

        if (rescue == 0 || rescue == 1)
        {
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            break;
        }

        if (tinyflag == 1)
        {
            if (remedy >= 1)
            {
                remedy -= 1;
                outtiny(HP, maxHP, tinyflag, tiny);
            }

            else
            {
                tiny -= 1;
                if (tiny == 0)
                {
                    outtiny(HP, maxHP, tinyflag, tiny);
                }
            }
        }

        if (frogflag == 1)
        {
            if (maidenkiss >= 1)
            {
                maidenkiss -= 1;
                outfrog(level, frogflag, frog, froglevel);
            }

            else
            {
                frog -= 1;
                if (frog == 0)
                {
                    outfrog(level, frogflag, frog, froglevel);
                }
            }
        }

        if (rescue == -1 && i == numEvent)
        {
            rescue = 1;
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            break;
        }

        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);

        i += 1;
    }
    fp.close();
}