#include<iostream>
using namespace std;

class ClockType
{
   public:
      void setTime(int, int, int);
      void printTime() const;
      void incrementSeconds();
      void incrementMinutes();
      void incrementHours();
      ClockType(int, int, int);
      ClockType();

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

void ClockType::incrementSeconds()
{
    sec += 1;
    if (sec >= 60)
    {
        sec -= 60;
        incrementMinutes();
    }
}
void ClockType::incrementMinutes()
{
    min += 1;
    if (min >= 60)
    {
        min -= 60;
        incrementHours();

    }
}
void ClockType::incrementHours()
{
    hr += 1;
    if (hr >= 24)
    {
        hr -= 24;
    }
}