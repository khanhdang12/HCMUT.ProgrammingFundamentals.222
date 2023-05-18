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

SCP createSCP(int id, int objClass, string speConProcedures, string description, string* addendums, int numAddendums)
{
    SCP haha;
    haha.id = id;
    haha.objClass = objClass;
    haha.speConProcedures = speConProcedures;
    haha.description = description;
    haha.addendums = addendums;
    haha.numAddendums = numAddendums;
    return haha;
}

int main()
{
    string* addendums = new string[2];
    addendums[0] = "Document #055-1: An Analysis of SCP-055\nThe author puts forward the hypothesis that SCP-055 was never formally acquired.";
    addendums[1] = "Document #055-2: Report of Dr. John Marachek\nSurvey team #19-055-127BXE was successfully able to enter SCP-055's container and ascertain the appearance.";

    SCP obj = createSCP(55, 2, "Object is kept within a five (5) by five (5) by two point five (2.5) meter square room.", "All known information about the object is that it is not round.", addendums, 2);

    for (int i = 0; i < 2; i++) cout << obj.addendums[i] << "\n";

    delete [] addendums;
    return 0;
}