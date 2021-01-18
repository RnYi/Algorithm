/*剑指offer15*/
#include <iostream>
using namespace std;

int hammingWeight(uint32_t n) 
{
    int cnt = 0;
    while(n!=0){
        cnt++;
        n = n & (n - 1);
    }
    return cnt;
}