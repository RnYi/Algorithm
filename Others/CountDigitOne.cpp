/*剑指offer43*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;
int countDigitOne(int n) 
{
    int count = 0;
    for (long i = 1; i <= n;i*=10){
        long high = n / i;
        long cur = high % 10;
        high = high / 10;
        long low = n % i;
        if (cur == 1)
        {
            count += high * i + low + 1;
        }
        else if (cur>1){
            count += (high + 1) * i;
        }else{
            count += high * i;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    cout << countDigitOne(12) << endl;
    return 0;
}
