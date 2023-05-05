#include <iostream>

using namespace std;

class ClockType
{
public:
    ClockType(int, int, int);
    ClockType();
    void printTime() const;
    void setTime(int, int, int);
    void getTime(int&, int&, int&) const;
    
private:
    int hr;
    int min;
    int sec;
};

void ClockType::printTime() const
{
   if (hr < 10)
      cout << "0";
   cout << hr << ":";
   if (min < 10)
      cout << "0";
   cout << min << ":";
   if (sec < 10)
      cout << "0";
   cout << sec;
}

void ClockType::getTime(int& a, int& b, int& c) const
{
    a = hr;
    b = min;
    c = sec;
}

// void ClockType::setTime(int a, int b, int c)
// {
//     hr = a;
//     min = b;
//     sec = c;
// }


// int main ()
// {
//     ClockType myClock; 
//     int hours; 
//     int minutes; 
//     int seconds;
//     myClock.getTime(hours, minutes, seconds); 
//     cout << "hours = " << hours << ", minutes = " << minutes << ", seconds = " << seconds << endl;
//     return 0;
// }