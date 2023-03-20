bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
 
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        return false;   
    }
    
    return true; 
}

int getSum(int n)
{
    int sum = 0;
    while (n != 0) 
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

bool isSpecialNumber(int n) 
{
    if (isPrime(n))
    {
        int i = getSum(n);
        if (isPrime(i))
        {
            return true;
        }
        
        else
        {
            return false;
        }
    }
    
    else
    {
        return false;
    }
}