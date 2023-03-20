int findMax(int *vals, int numEls) 
{
    int max = -9999;
    for (int i = 0; i < numEls; i++)
    {
        if (vals[i] > max)
        {
            max = vals[i];
        }
    }
    return max;
}