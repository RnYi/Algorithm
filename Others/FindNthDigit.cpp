/*剑指offer44*/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
int findNthDigit(int n) 
{
    long start, digit, count;
    start = 1;
    digit = 1;
    count = 9 * start * digit;
    while(n>count){
        n -= count;
        start *= 10;
        digit += 1;
        count = 9 * start * digit;
    }
    int num = start + ((n - 1) / digit);
    n = (n - 1) % digit;
    return to_string(num).at(n) - '0';
}
