#include<iostream>
using namespace std;

class Integer
{
private:
    int val;
public: 
    Integer(int);
    Integer(Integer*);
    void print();
    Integer operator+(int);
    Integer operator+(Integer&);
};

void Integer::print() {
    cout << this->val << endl;
}

Integer::Integer(int val) 
{
    this->val = val;
}

Integer::Integer(Integer* integerPtr) 
{
    this->val = integerPtr->val;
}

Integer Integer::operator+(Integer & other)
{
    return Integer(this->val + other.val);
}

Integer Integer::operator+(int value)
{
    return Integer(this->val + value);
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    Integer a(x);
    Integer b(y);
    Integer* t = new Integer(z);
    Integer c(t);
    
    a.print(); b.print();
    (a + b + c + 4).print();
    
    delete t;
    return 0;
}