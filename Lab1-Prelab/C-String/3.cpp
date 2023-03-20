double pow(double base, int exponent) 
{
    double result = 1.0;
    bool isNegative = false;
    if (exponent < 0) 
    {
        isNegative = true;
        exponent = -exponent;
    }
    for (int i = 0; i < exponent; i++) 
    {
        result *= base;
    }
    if (isNegative) 
    {
        result = 1.0 / result;
    }
    return result;
}

int calc(char str[]) 
{
    int len = strlen(str);
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '1')
        {
            sum = sum + (int)pow(2, len - i - 1);
        }
    }
    return sum;
}