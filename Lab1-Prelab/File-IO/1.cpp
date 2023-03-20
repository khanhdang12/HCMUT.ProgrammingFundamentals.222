void calSum(string fileName)
{
    int sum = 0;
    int number;

    ifstream file(fileName);
    if (file.is_open())
    {
        while (file >> number)
        {
            sum += number;
        }
    }
    else
    {
        cout << "Error: File not found" << endl;
    }

    cout << sum << endl;
}