#include <iostream>

using namespace std;

void swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main()
{
    int a = 5;
    int b = 6;
    swap(&a, &b);
    cout << a << ' ' << b;
    return 0;
}