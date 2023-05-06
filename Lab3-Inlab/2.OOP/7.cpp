// string.h is included
#include<iostream>
#include<string.h>

using namespace std;

class Book 
{
    char* name;
public:
    Book(const char*);
    ~Book();
    
    void display();
    char* getName();
};

void Book::display() {
    cout << "Book: " << this->name << endl;
}

char* Book::getName() {
    return this->name;
}

Book::Book(const char* title)
{
    int length = strlen(title) + 1;
    name = new char[length];
    strcpy(name, title);
}
Book::~Book()
{
    delete[] name;
}