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
bool is_prime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int nearest_prime(int n)
{
    int prime = 0;
    int i = n + 1;
    while (true)
    {

        if (is_prime(i))
        {
            prime = i;
            break;
        }
        i++;
    }
    return prime;
}
int nearest_Fibonacci(int n)
{
    int first = 0;
    int second = 1;
    int third = first + second;
    while (third < n)
    {
        first = second;
        second = third;
        third = first + second;
    }
    return second;
}
void adventureToKoopa(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue)
{
    int event = 0;
    int level0 = 0;
    int numEvent = 0;
    int row = 0, col = 0;
    int merlin1 = 0;
    int ascle = 0;
    int reme = 0;
    int maid = 0;
    int phoe = 0;
    int arthur = 0;
    int lancelot = 0;
    if (HP == 999)
    {
        arthur = 1;
    }

    else if (is_prime(HP))
    {
        lancelot = 1;
    }
    // Them vao
    string str = "", mush = "", asc = "", merlin = "", temp = "";
    ifstream fp;
    fp.open(file_input);
    getline(fp, str);
    getline(fp, str);
    getline(fp, str);
    fp.close();

    int var1 = 0, var2 = 1;
    while (str[var1] != '\0')
    {
        if (str[var1] == ',')
        {
            if (var2 == 1)
            {
                mush = temp;
                var2++;
                temp = "";
            }

            else if (var2 == 2)
            {
                asc = temp;
                var2++;
                temp = "";
            }
        }

        else
        {
            temp += str[var1];
        }
        var1++;
    }
    merlin = temp;

    // ifstream inputpack1;
    // inputpack1.open("/Users/thanhvipintro/Dozcuments/KTLT231/initial/asclepius_pack");
    //     inputpack1>>row;
    //     inputpack1>>col;
    //     for (int r = 0; r < row; r++)
    // {
    //     for (int c = 0; c < col; c++)
    //     {
    //       inputpack1 >> arr1[r][c];
    //     }
    // }

    // inputpack1.close();
    ifstream inputrun;
    inputrun.open(file_input);
    int k;
    while (inputrun >> k)
    {
        numEvent++;
    }
    numEvent -= 5;
    inputrun.close();

    ifstream input;
    input.open(file_input);

    rescue = -1;
    input >> HP;
    input >> level;
    input >> remedy;
    input >> maidenkiss;
    input >> phoenixdown;
    int i = 1;
    int maxHP = HP;
    int baseDamage;
    int damage;
    bool tiny = false;
    int counttiny = 0;
    int HPBeforetiny = 0;
    bool frog = false;
    int countfrog = 0;
    int levelBeforeFrog = 0;

    while (input >> event)
    {

        if (event == 0)
        {
            rescue = 1;
        }
        if (1 <= event && event <= 5)
        {
            int b = i % 10;
            int levelO = i > 6 ? (b > 5 ? b : 5) : b;
            if (level > levelO || arthur == 1 || lancelot == 1)
            {
                level += 1;
                if (level > 10)
                {
                    level = 10;
                }
            }
            else if (level == levelO)
            {
            }
            else
            {
                if (event == 1)
                {
                    damage = 1 * levelO * 10;
                    HP -= damage;

                    if (HP <= 0)
                    {
                        if (phoenixdown > 0)
                        {
                            HP = maxHP;
                            phoenixdown -= 1;
                        }
                        else
                            rescue = 0;
                    }
                }
                if (event == 2)
                {
                    damage = 1.5 * levelO * 10;
                    HP -= damage;

                    if (HP <= 0)
                    {
                        if (phoenixdown > 0)
                        {
                            HP = maxHP;
                            phoenixdown -= 1;
                        }
                        else
                            rescue = 0;
                    }
                }
                if (event == 3)
                {
                    damage = 4.5 * levelO * 10;
                    HP -= damage;

                    if (HP <= 0)
                    {
                        if (phoenixdown > 0)
                        {
                            HP = maxHP;
                            phoenixdown -= 1;
                        }
                        else
                            rescue = 0;
                    }
                }
                if (event == 4)
                {
                    damage = 7.5 * levelO * 10;
                    HP -= damage;

                    if (HP <= 0)
                    {
                        if (phoenixdown > 0)
                        {
                            HP = maxHP;
                            phoenixdown -= 1;
                        }
                        else
                            rescue = 0;
                    }
                }
                if (event == 5)
                {
                    damage = 9.5 * levelO * 10;
                    HP -= damage;

                    if (HP <= 0)
                    {
                        if (phoenixdown > 0)
                        {
                            HP = maxHP;
                            phoenixdown -= 1;
                        }
                        else
                            rescue = 0;
                    }
                }
            }
        }
        if (event == 6)
        {
            int b = i % 10;
            int levelO = i > 6 ? (b > 5 ? b : 5) : b;
            if (tiny == true)
            {
            }
            else if (level > levelO || arthur == 1 || lancelot == 1) 
            {
                level += 2;
                if (level > 10)
                {
                    level = 10;
                }
            }
            else if (level == levelO)
            {
            }
            else if (level < levelO)
            {
                tiny = true;
                counttiny = 0;
                HPBeforetiny = HP;
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
        if (event == 7)
        {
            int b = i % 10;
            int levelO = i > 6 ? (b > 5 ? b : 5) : b;
            if (frog)
            {
            }
            else if (level > levelO || arthur == 1 || lancelot == 1)
            {
                level += 2;
                if (level > 10)
                {
                    level = 10;
                }
            }
            else if (level == levelO)
            {
            }
            else if (level < levelO)
            {
                frog = true;
                countfrog = 0;
                levelBeforeFrog = level;
                level = 1;
            }
        }
        if (event == 15)
        {
            remedy += 1;
            if (remedy > 99)
            {
                remedy = 99;
            }
        }
        if (event == 16)
        {
            maidenkiss += 1;
            if (maidenkiss > 99)
            {
                maidenkiss = 99;
            }
        }
        if (event == 17)
        {
            phoenixdown += 1;
            if (phoenixdown > 99)
            {
                phoenixdown = 99;
            }
        }

        if (event == 11)
        {
            int n1 = 0;
            int s1 = 0;
            n1 = ((level + phoenixdown) % 5 + 1) * 3;
            for (int j = 0; j < n1; j++)
            {
                s1 = (100 - (2 * j + 1));
            }

            HP = HP + (s1 % 100);
            HP = nearest_prime(HP);
            if (HP > maxHP)
            {
                HP = maxHP;
            }
        }
        if (event == 12)
        {
            if (HP > 1)
            {
                HP = nearest_Fibonacci(HP);
            }
            else if (HP == 1)
            {
            }
            // if (event >= 130)
            // {
            //     ifstream fp;
            //     fp.open(mush);
            //     //todo
            //     fp.close();
            // }

            if (event == 18)
            {
                if (merlin1 == 0)
                {
                    merlin1++;
                    ifstream fp;
                    fp.open(merlin);
                    int n9 = 0;
                    fp >> n9;
                    string input = "";

                    while (fp >> input)
                    {
                        if (input.find("Merlin") != std::string::npos)
                        {
                            HP += 3;
                        }

                        else
                        {
                            if (input.find("merlin") != std::string::npos)
                            {
                                HP += 3;
                            }

                            else
                            {
                                int tu1 = 0;
                                int tu2 = 0;
                                int tu3 = 0;
                                int tu4 = 0;
                                int tu5 = 0;
                                int tu6 = 0;
                                int len = input.length();
                                for (int iterate = 0; iterate < len; iterate++)
                                {
                                    if (input[iterate] == 'M' || input[iterate] == 'm')
                                    {
                                        tu1 = 1;
                                    }
                                    else if (input[iterate] == 'E' || input[iterate] == 'e')
                                    {
                                        tu2 = 1;
                                    }
                                    else if (input[iterate] == 'R' || input[iterate] == 'r')
                                    {
                                        tu3 = 1;
                                    }
                                    else if (input[iterate] == 'L' || input[iterate] == 'l')
                                    {
                                        tu4 = 1;
                                    }
                                    else if (input[iterate] == 'I' || input[iterate] == 'i')
                                    {
                                        tu5 = 1;
                                    }
                                    else if (input[iterate] == 'N' || input[iterate] == 'n')
                                    {
                                        tu6 = 1;
                                    }

                                    if (tu1 == 1 && tu2 == 1 && tu3 == 1 && tu4 == 1 && tu5 == 1 && tu6 == 1)
                                    {
                                        HP += 2;
                                    }
                                }

                                if (HP > maxHP)
                                {
                                    HP = maxHP;
                                }
                            }
                        }
                    }

                    fp.close();
                }
            }
        }
        if (event == 19)
        {
            if (ascle == 0)
            {
                ascle++;
                ifstream fp;
                fp.open(asc);
                int row, col;
                fp >> row;
                fp >> col;
                int arr[row][col];

                for (int i = 0; i < row; i++)
                {
                    for (int j = 0; j < col; j++)
                    {
                        fp >> arr[i][j];
                    }
                }

                for (int r = 0; r < row; r++)
                {
                    int countascle = 0;
                    for (int c = 0; c < col; c++)
                    {
                        if (countascle >= 3)
                        {
                            break;
                        }
                        else
                        {
                            if (arr[r][c] == 16)
                            {
                                countascle++;
                                reme++;
                            }
                            else if (arr[r][c] == 17)
                            {
                                countascle++;
                                maid++;
                            }
                            else if (arr[r][c] == 18)
                            {
                                phoe++;
                                countascle++;
                            }
                        }
                    }
                }
                remedy += reme;
                maidenkiss += maid;
                phoenixdown += phoe;
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
        if (event == 99)
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
        if (tiny == true)
        {
            if (remedy >= 1)
            {
                remedy -= 1;
                if (counttiny == 0)
                {
                    HP = HPBeforetiny;
                    tiny = false;
                }
                else
                {
                    HP = HP * 5;
                    tiny = false;
                }
            }
            else if (phoenixdown >= 1 && HP <= 0)
            {
                phoenixdown -= 1;
                HP = HPBeforetiny;
                tiny = false;
            }

            else
            {
                counttiny++;
                if (counttiny == 4)
                {
                    HP = HP * 5;
                    if (HP > maxHP)
                    {
                        HP = maxHP;
                    }
                }
            }
        }

        if (frog)
        {
            if (maidenkiss >= 1)
            {
                maidenkiss -= 1;
                level = levelBeforeFrog;
            }

            else
            {
                countfrog++;
                if (countfrog == 4)
                {
                    level = levelBeforeFrog;
                }
            }
        }
        if (rescue == 0 || rescue == 1)
        {
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            break;
        }
        if (rescue == -1 && i == numEvent)
        {
            rescue = 1;
            display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
            break;
        }

        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
        i++;
    }
}