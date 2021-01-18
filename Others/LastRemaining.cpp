#include <iostream>
using namespace std;

int lastRemaining(int n, int m) 
{
    if(n==1)
        return 0;
    return (lastRemaining(n - 1, m) + m) % n;
}

int main(int argc, char const *argv[])
{
    cout << lastRemaining(10, 17) << endl;
    return 0;
}
