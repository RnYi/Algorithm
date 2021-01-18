/* 剑指offer50 */
#include <iostream>
#include <algorithm>
using namespace std;

int nthUglyNumber(int n) 
{
    int *dp = new int[n + 1]();
    dp[1] = 1;
    int p2, p3, p5;
    p2 = p3 = p5 = 1;
    for (int i = 2; i <= n;++i){
        int p2x2 = dp[p2] * 2;
        int p3x3 = dp[p3] * 3;
        int p5x5 = dp[p5] * 5;
        dp[i] = min({p2x2, p3x3, p5x5});
        if(dp[i]==p2x2){
            p2++;
        }
        if(dp[i]==p3x3){
            p3++;
        }
        if(dp[i]==p5x5){
            p5++;
        }
    }

    return dp[n];
}