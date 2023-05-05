#include <iostream>

using namespace std;

class Room
{
public:
    float length;
    float breadth;
    float height;
    Room(float a, float b, float c)
    {
        length = a;
        breadth = b;
        height = c;
    }

    float calculateArea()
    {
        return length * breadth;
    }

    float calculateVolume()
    {
        return length * breadth * height;
    }
};

// int main()
// {
//     cout<<"Constructor test";
//     Room r(20,3,4);
//     Room *r2=new Room(10.5,5.5,5.4);
//     delete r2;
// }