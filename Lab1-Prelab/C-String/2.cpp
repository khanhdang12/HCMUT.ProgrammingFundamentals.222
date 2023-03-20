void process(const char *str, char *outstr) 
{
    int j = 0;
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--)
    {
        outstr[j++] = str[i];
    }
    outstr[len] = '\0';
}