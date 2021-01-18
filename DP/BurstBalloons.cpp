/* Leetcode312*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxScore(vector<int>& nums)
{
    int len = nums.size();
    int* points = new int[len + 2];
    points[0] = points[len + 1] = 1;
    for (int i = 1; i <= len;++i){
        points[i] = nums[i - 1];
    }
    int **dp = new int *[len + 2];
    for (int i = 0; i < len + 2; ++i)
    {
        dp[i] = new int[len + 2]();
    }

    for (int i = len; i >= 0; --i)
    {
        for (int j = i + 1; j < len + 2; ++j)
        {
            for (int k = i + 1; k < j; ++k)
            {
                dp[i][j] = max(dp[i][j],
                               dp[i][k] + dp[k][j] + points[i] * points[j] * points[k]);
            }
        }
    }

    return dp[0][len + 1];
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
