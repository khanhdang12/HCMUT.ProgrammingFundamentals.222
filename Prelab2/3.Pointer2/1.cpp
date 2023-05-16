int* zeros(int n) 
{
    if (n <= 0)
    {
        return nullptr;
    }
    int *arr = new int[n];


    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
    return arr;
}