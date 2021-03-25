// Leetcode 754
#include <stdio.h>
#include <math.h>
using namespace std;

int reachNumber(int target)
{
    target=abs(target);
    if(target==0)return 0;
    int step=ceil(sqrt(2*target+0.25)-0.5);
    int sum=step*(step+1)/2;
    while((sum-target)%2!=0){
        ++step;
        sum+=step;
    }
    return step;
}

int main(void)
{
    printf("step = %d\n", reachNumber(5));
    return 0;
}
