#include <iostream>
#include <string>

using namespace std;

int main()  
{
    string s;
    getline(cin, s);
    int len = s.length();
    
    int count = 1;
    int countmax = 1;
    
    for (int i = 0; i < len; i++)
    {
        if (s[i] == s[i + 1])
        {
            count += 1;
            if (count > countmax)
            {
                countmax = count;
            }
        }
        
        else
        {
            count = 1;
        }
    }
    
    cout << countmax << endl;
    return 0;
}