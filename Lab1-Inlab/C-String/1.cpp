void process(const char *name, char *outstr) 
{
    int len = strlen(name);
    int j = 0;
    bool isFirstCharacter = true;
    for (int i = 0; i < len; i++)
    {
        if (name[i] >= 65 && name[i] <= 90)
        {
            outstr[j++] = (isFirstCharacter ? name[i] : (char)(name[i] + 32));
            isFirstCharacter = false;
        }
        else if (name[i] >= 97 && name[i] <= 122)
        {
            outstr[j++] = (isFirstCharacter ? (char)(name[i] - 32) : name[i]);
            isFirstCharacter = false;
        }
        else if (name[i] == ' ')
        {
            if (j > 0 && outstr[j - 1] != ' ')
            {
                outstr[j++] = ' ';
                isFirstCharacter = true;
            }
        }
    }
    if (j > 0 && outstr[j - 1] == ' ')
    {
        j--;
    }
    outstr[j] = '\0';
}