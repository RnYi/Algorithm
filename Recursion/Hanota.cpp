#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void Move(int n,const string& from,const string& to)
{
    cout << "Move " << n << " from " << from << " to " << to << endl;
}

void Hanota(int n,const string& from,const string& buffer,const string& to,int& steps)
{
    if(n==1){
        Move(n, from, buffer);
        ++steps;
        Move(n, buffer, to);
        ++steps;
        return;
    }
    Hanota(n - 1, from, buffer, to,steps);
    Move(n, from, buffer);
    ++steps;
    Hanota(n - 1, to, buffer, from, steps);
    Move(n, buffer, to);
    ++steps;
    Hanota(n - 1, from, buffer, to,steps);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int steps = 0;
    Hanota(n, "left", "mid", "right",steps);
    cout << "It will move "<<steps<<" steps."<< endl;
    return 0;
}
