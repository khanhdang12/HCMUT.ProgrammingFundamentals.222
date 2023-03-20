#include <iostream>

using namespace std;

int fac(int n)
{
    if (n == 1)
    {
        return 1;
    }
    
    else
    {
        return n * fac(n - 1);
    }
}

int main(int narg, char** argv)
{
    int N;
    cin >> N;
    long result;
    result = fac(N);
    cout << result << endl;
    return 0;
}