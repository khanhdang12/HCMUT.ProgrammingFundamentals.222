#include<iostream>
#include<string>
using namespace std;

struct SCP {
    int id;
    int objClass;
    string speConProcedures;
    string description;
    string* addendums;
    int numAddendums;
};

string convertToString(SCP obj)
{
    if (obj.id < 100)
    {
        if (obj.id < 10)
        {
            cout << "Item #: SCP-00" << obj.id << endl;
        }

        else
        {
            cout << "Item #: SCP-0" << obj.id << endl;
        }
        
    }

    else
    {
        cout << "Item #: SCP-" << obj.id << endl;
    }

    switch (obj.objClass)
    {
        case 0:
        {
            cout << "Object Class: Safe" << endl;
            break;
        }
        case 1:
        {
            cout << "Object Class: Euclid " << endl;
            break;
        }
        case 2:
        {
            cout << "Object Class: Keter  " << endl;
            break;
        }
    }

    cout << "Special Containment Procedures: " << obj.speConProcedures << endl;
    cout << "Description: " << obj.description << endl;
    for (int i = 0; i < obj.numAddendums; i++)
    {
        cout << obj.addendums[i] << endl;
    }
    return "";
}

int main()
{
    string* addendums = new string[2];
    addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
    addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

    SCP obj {55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2};

    cout << convertToString(obj);

    delete [] addendums;
    return 0;
}