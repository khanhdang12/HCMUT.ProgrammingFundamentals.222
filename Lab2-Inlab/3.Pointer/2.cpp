#include<iostream>
using namespace std;

void addElement(int*& arr, int n, int val, int index) 
{
    int * newArr = new int[n + 1];

        for (int i = 0; i < n + 1; i++) 
        {
            if (i < index) 
            {
                newArr[i] = arr[i];  
            } 
            
            else if (i == index) 
            {
                newArr[i] = val;  
            } 
            
            else 
            {
                newArr[i] = arr[i - 1];  
            }
    }

    delete[] arr;
    arr = newArr;
}


int main()
{
    return 0;
}

/*
arr = {1,2,3,5,6};
n = 5;
val = 4
index = 3
*/