int count = 0;

void print2(int n, int count)
{
    if (count != 0)
    {
        n += 5;
        cout << n << " ";
        count--;
        print2(n, count);
    }
}

void printPattern(int n)
{
    cout << n << " ";
    
    if (n > 0)
    {
        n -= 5;
        count++;
        printPattern(n);
    }
    
    else
    {
        print2(n,count);
    }
}