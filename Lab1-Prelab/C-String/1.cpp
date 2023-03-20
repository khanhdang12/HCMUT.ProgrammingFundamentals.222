void process(char str[], char outstr[]) 
{
    int i = 0;
    int len = strlen(str);
    while (str[i] == ' ' && i < len)
    {
        i++;
    }

    int j = 0;
    for (int temp = i; temp < len; temp++)
    {
        if (str[temp] != ' ' || (j > 0 && outstr[j - 1] != ' '))
        {
            outstr[j++] = str[temp];
        }
    }
    outstr[j] = '\0';
}