int len = 0;

int strLen(char* str)     
{ 
    if (str[len] == '\0')
    {
        return 0;
    }
    
    else
    {
        return 1 + strLen(str + 1);
    }
}