#include<iostream>

using namespace std;

class Course 
{
    private:
        int ID;
        int numOfStudent;
        int numOfTeacher;
        int numOfTA;
    public:
        void getinfo();
        void disinfo();
};

void Course::getinfo() 
{
   cout << "ID: ";
   cin >> ID;
   cout << "Number of Students: ";
   cin >> numOfStudent;
   cout << "Number of Teachers: ";
   cin >> numOfTeacher;
   cout << "Number of TAs: ";
   cin >> numOfTA;
}

void Course::disinfo()
{
   cout<<endl;
   cout<< "CourseID = "<< ID << endl;
   cout<< "Number of student = " << numOfStudent << endl;
   cout<< "Number of teacher = " << numOfTeacher << endl;
   cout<< "Number of TA = " << numOfTA<< endl;
}


int main() 
{
    int n = 0;
    cin >> n;

    int ID, numOfStudent, numOfTeacher, numOfTA;

    Course * arr = new Course[n];

    for (int i = 0; i < n; i++)
    {
        arr[i].getinfo();
    }    

    for (int i = 0; i < n; i++)
    {
        arr[i].disinfo();
    }    
    return 0;
}