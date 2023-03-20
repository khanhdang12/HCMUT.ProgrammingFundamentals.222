void sum2(int * array, int numEls, int &result)
{
    result = 0;
    for (int i = 0; i < numEls; i++)
    {
        result += array[i];
    }
}