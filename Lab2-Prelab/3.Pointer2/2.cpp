#include <iostream>

using namespace std;

void shallowCopy(int*& newArr, int*& arr) 
{
    newArr = arr;
}

int main()
{
    int* arr = new int[2];
    arr[0] = 2; arr[1] = 3;
    int* newArr = nullptr;
    shallowCopy(newArr, arr);
    cout << newArr[0] << ' ' << newArr[1];
    delete[] arr;

    return 0;
}