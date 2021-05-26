// Leetcode 1787
#include <stdint.h>
#include <stdio.h>
#include <unordered_map>
#include <vector>
using namespace std;

int minChanges(vector<int>& nums, int k)
{
    // 根据题意可推出，应使nums以k为周期循环
    int N = nums.size();
    // 将idx%k相同的划分到一组，每组数字应当相同
    // nums[0], nums[1],   ... , nums[k-1],
    // nums[k], nums[k+1], ... , nums[2k-1],
    // ...
    // 每一列为一组
    int gRow = (N + k - 1) / k;
    int gIdx = N % k;
    constexpr int XOR_MAX = 1024;

    // dp[i][x]表示前i列（i从0开始）异或为x的最少更改次数
    // 由于dp[i]仅与dp[i-1]有关，所以可以降至一维
    int dp0[XOR_MAX];
    int dp1[XOR_MAX];
    // dpMin记录dp[i-1]的最小值
    int dpMin = INT32_MAX;
    int* oldDp = dp0;
    int* newDp = dp1;
    // 第0列
    unordered_map<int, int> numCnt;
    for (int i = 0; i < N; i += k) {
        ++numCnt[nums[i]];
    }
    for (int x = 0; x < XOR_MAX; ++x) {
        newDp[x] = gRow - numCnt[x];
        dpMin = min(dpMin, newDp[x]);
    }
    // 其他列
    for (int i = 1; i < k; ++i) {
        int* tmp = oldDp;
        oldDp = newDp;
        newDp = tmp;
        numCnt.clear();
        for (int j = i; j < N; j += k) {
            ++numCnt[nums[j]];
        }
        int dpMinTmp = INT32_MAX;
        int curGRow = i % k < gIdx || gIdx == 0 ? gRow : gRow - 1;
        for (int x = 0; x < XOR_MAX; ++x) {
            // 这一列全部替换
            newDp[x] = dpMin + curGRow;
            // 部分替换
            for (auto it = numCnt.begin(); it != numCnt.end(); ++it) {
                newDp[x] = min(newDp[x], oldDp[x ^ it->first] + curGRow - it->second);
            }
            dpMinTmp = min(dpMinTmp, newDp[x]);
        }
        dpMin = dpMinTmp;
    }
    return newDp[0];
}

int main(void)
{
    vector<int> nums = { 3, 4, 5, 2, 1, 7, 3, 4, 7 };
    int k = 3;
    printf("minChanges(nums, k) = %d\n", minChanges(nums, k));
    return 0;
}
