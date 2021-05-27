#include <algorithm>
#include <stdint.h>
#include <stdio.h>
#include <vector>
using namespace std;

int hammingDistance(int x, int y)
{
    x^=y;
    int count=0;
    while(x){
        x&=(x-1);
        ++count;
    }
    return count;
}

int main(void)
{
    int x=1;
    int y=4;
    printf("hammingDistance(x,y) = %d\n", hammingDistance(x,y));
    return 0;
}
