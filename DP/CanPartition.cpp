/* Leetcode416 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPartition(vector<int>& nums)
{
    int sum = 0;
    for (auto num:nums)
        sum += num;
    if (sum% 2 != 0)
        return false;
    sum = sum / 2;
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = sum; j >= 0;--j){
            if(j-nums[i]>=0)
                dp[j] = dp[j] || dp[j - nums[i]];
        }
    }

    return dp[sum];
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
