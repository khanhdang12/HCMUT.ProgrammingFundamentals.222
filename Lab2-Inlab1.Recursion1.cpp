#include<iostream>
using namespace std;

bool checkDuplicate(int* ar,int size)
{
    if (size <= 1)
    {
        return true;
    }

    for (int i = 1; i < size; i++)
    {
        if (ar[0] == ar[i]) 
        {
            return false;
        }
    }
    
    size -= 1;
    if (size == 1)
    {
        return true;
    }

    return checkDuplicate(ar + 1, size);
}

int main()
{
    int arr[5] = {1,2,3,4,5};

    if(checkDuplicate(arr,5))
    {
        cout << "yes";
    }

    else
    {
        cout << "No";
    }
    return 0;
}
