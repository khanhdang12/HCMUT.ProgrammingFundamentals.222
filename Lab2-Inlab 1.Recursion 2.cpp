#include <iostream>
using namespace std;

int recursiveSearch(int& n , int m, int arr[], int index)
{
    if (index > n)
    {
        return -1;
    }

    if (arr[index] == m)
    {
        if (index == n)
        {
            arr[index] = 0;
            n -= 1;
            return index;
        }

        for (int i = index; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        n -= 1;
        return index;
    }

    return recursiveSearch(n, m, arr, index + 1);
}



int main()
{
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 15};
    recursiveSearch(n, 15, arr, 0);
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
