void threeChars(string fileName) 
{
    fstream newFile;
    newFile.open(fileName, ios::in);
    if (newFile.is_open()) 
    {
        string tp;
        while (getline(newFile, tp)) 
        {
            if (tp == "***") 
            {
                break;
            } else 
            {
                bool isCorrectOrder = tp[0] <= tp[1] && tp[1] <= tp[2];
                if (isCorrectOrder) 
                {
                    cout << "true" << endl;
                } else 
                {
                    cout << "false" << endl;
                }
            }
        }
        newFile.close();
    }
}
