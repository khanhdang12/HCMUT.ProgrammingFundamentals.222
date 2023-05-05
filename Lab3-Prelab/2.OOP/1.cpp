#include <iostream>

using namespace std;

class Integer
{
private:
    int val;
public:
    Integer(int val1)
    {
        val = val1;
    }
    void setValue(int val1)
    {
        val = val1;
    }
    int getValue()
    {
        return val;
    }
};

// int main()
// {
//     cout<<"Constructor test";
//     Integer i(10);
//     Integer i2(-10);
//     Integer *i3=new Integer(20);
//     delete i3;
// }