/* Leetcode15 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) 
{
    int len = nums.size();
    if(len<3)
        return {};
    vector<vector<int>> ans;
    int i, j, k;
    sort(nums.begin(), nums.end());
    for (i = 0; i < len;++i){
        if(i>0&&nums[i]==nums[i-1]){
            continue;
        }
        k = len - 1;
        int target = -nums[i];
        for (j = i + 1; j < len;++j){
            if(j>i+1 && nums[j]==nums[j-1]){
                continue;
            }
            while(j<k && nums[j]+nums[k]>target){
                --k;
            }
            if(j==k){
                break;
            }
            else if(nums[j]+nums[k]==target){
                ans.push_back({nums[i], nums[j], nums[k]});
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    return 0;
}
