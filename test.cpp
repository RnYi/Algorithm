#include <algorithm>
#include <array>
#include <vector>

using namespace std;

int rob_help(vector<int>& nums, int start, int end)
{
    if(start>end){
        return 0;
    }
    array<int, 2> dp{0};
    for(int i=start;i<=end;++i){
        int tmp = dp[1];
        dp[1] = max(dp[0]+nums[i], dp[1]);
        dp[0] = tmp;
    }
    return dp[1];
}

int rob(vector<int>& nums)
{
    int N = nums.size();
    int ans0 = rob_help(nums, 0, N-2);
    int ans1 = rob_help(nums, 1, N-1);
    return max({nums[0], ans0, ans1});
}

int main(void)
{
    vector<int> nums = {2,3,2};
    printf("rob(nums) = %d\n", rob(nums));
    return 0;
}
