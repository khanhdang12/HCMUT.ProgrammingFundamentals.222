void encrypt(char* text, int shift) 
{
    int num = shift % 26;
    int l = 0;
    while (text[l] != '\0')
    {
        l++;
    }
    
    for (int i = 0; i < l; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = ((text[i] - 'a' + num) % 26) + 'a';
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = ((text[i] - 'A' + num) % 26) + 'A';
        }
    }
}

void decrypt(char* text, int shift) 
{
    int num = shift % 26;
    int l = 0;
    while (text[l] != '\0')
    {
        l++;
    }
    
    for (int i = 0; i < l; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = ((text[i] - 'a' - num + 26) % 26) + 'a';
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = ((text[i] - 'A' - num + 26) % 26) + 'A';
        }
    }
}