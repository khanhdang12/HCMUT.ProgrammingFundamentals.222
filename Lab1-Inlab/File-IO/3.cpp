void process(string fileName) 
{
    ifstream myfile;
    myfile.open(fileName);
    int row,col;
    myfile>>row>>col;
    double MaxOfLine[row],temp;
    for(int i=0;i<row;i++)
    {
        myfile>>MaxOfLine[i];
        for(int j=1;j<col;j++)
        {
            myfile>>temp;
            if(MaxOfLine[i]<temp)
            {
                MaxOfLine[i]=temp;
            }
        }
    cout<<MaxOfLine[i]<<' ';
    }
    double MaxOfAll=MaxOfLine[0];
    for(int i=1;i<row;i++)
    {
        if(MaxOfAll<MaxOfLine[i])
        {
            MaxOfAll=MaxOfLine[i];
        }
    }   
    cout<<MaxOfAll;
    myfile.close();
}