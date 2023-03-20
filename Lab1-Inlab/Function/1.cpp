bool isPalindrome(const char* str) 
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    
    bool flag = true;
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            flag = false;
            break;
        }
    }
    
    if (flag == false)
    {
        return false;
    }
    
    else
    {
        return true;
    }
}