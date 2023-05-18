#include<iostream>
using namespace std;

int lendokaka (char* str)
{
    int i = 0;
    while (*str != '\0')
    {
        i++;
        str++;
    }
    return i;
}

char* concatStr(char* str1, char* str2) 
{
    int a = lendokaka(str1), b = lendokaka(str2);

    char * str = new char[a + b];

    for (int i = 0; i < a; i++)
    {
        str[i] = *str1++;
    }

    for (int i = a; i < a + b; i++)
    {
        str[i] = *str2++;
    }
    str[a + b] = '\0';
    return str;
}

int main()
{
    char s1[] = "Hello, ";
    char s2[] = "how are you?";
    char* s = concatStr(s1, s2);
    cout << s;
    delete[] s;
}