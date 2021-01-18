/* 剑指offer60 */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector<double> twoSum(int n) {
    int counts = pow(6, n);
    int *dp = new int[6 * n + 1]();
    for (int i = 1; i <= 6;++i)
        dp[i] = 1;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 6 * i; j >= i; --j)
        {
            dp[j] = 0;
            for (int cur = 1; cur <= 6; ++cur)
            {
                if (j - cur < i-1)
                {
                    break;
                }
                dp[j] += dp[j - cur];
            }
        }
    }
    vector<double> rtv(6 * n - n + 1);
    for (int i = n; i <= 6 * n;++i){
        rtv[i - n] = dp[i]*1.0 / counts;
    }

    return rtv;
}

int main(int argc, char const *argv[])
{
    return 0;
}
