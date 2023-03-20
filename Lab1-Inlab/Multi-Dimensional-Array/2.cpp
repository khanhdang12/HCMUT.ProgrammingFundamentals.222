bool isPrime(int n)
{
    if (n <= 1)
        return false;
 
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
 
    return true;
}

int primeColumns(int arr[][1000], int row, int col) 
{
    int sum;
    int count = 0;
    for (int j = 0; j < col; j++)
    {
        sum = 0;
        for (int i = 0; i < row; i++)
        {
            sum += arr[i][j]; 
        }
        if (isPrime(sum))
        {
            count ++;
        }
    }
    return count;
}