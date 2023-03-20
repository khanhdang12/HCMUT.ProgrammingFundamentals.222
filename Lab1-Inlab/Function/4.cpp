bool checkElementsUniqueness(int* arr, int n) 
{
    int check;
    for (int i = 0; i < n; i++)
    {
        check = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                check++;
            }
        }
        if (check >= 2)
        {
            return false;
        }
    }
    return true;
}