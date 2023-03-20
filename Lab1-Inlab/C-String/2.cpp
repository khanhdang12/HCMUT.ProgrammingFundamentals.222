void printFirstRepeatedWord(char str[]) 
{
    int len = strlen(str);
    char words[len][len];
    int wordCount = 0;
    int j = 0;
    
    for (int i = 0; i <= len; i++) 
    {
        if (str[i] == ' ' || str[i] == '\0') 
        {
            words[wordCount][j] = '\0';
            wordCount++;
            j = 0;
        } 
        
        else 
        {
            words[wordCount][j] = str[i];
            j++;
        }
    }
    
    for (int i = 0; i < wordCount; i++) 
    {
        for (int j = i + 1; j < wordCount; j++) 
        {
            if (strcmp(words[i], words[j]) == 0 && i - j != 1 && j - i != 1) 
            {
                cout << words[i];
                return;
            }
        }
    }
    
    cout << "No Repetition";
}    