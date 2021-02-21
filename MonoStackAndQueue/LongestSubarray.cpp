// Leetcode 1438
#include <stdio.h>
#include <deque>
#include <vector>
using namespace std;

int longestSubarray(vector<int>& nums, int limit)
{
    int N=nums.size();
    int ans=0;
    int left=0;
    int right=0;
    int curNums;
    deque<int> minQ, maxQ;
    while(right<N){
        curNums=nums[right++];
        while(!minQ.empty() && minQ.back()>curNums){
            minQ.pop_back();
        }
        minQ.push_back(curNums);
        while(!maxQ.empty() && maxQ.back()<curNums){
            maxQ.pop_back();
        }
        maxQ.push_back(curNums);

        while(maxQ.front()-minQ.front() > limit){
            curNums=nums[left++];
            if(curNums==minQ.front()){
                minQ.pop_front();
            }
            if(curNums==maxQ.front()){
                maxQ.pop_front();
            }
        }
        ans=max(ans, right-left);
    }
    return ans;
}

int main()
{
    vector<int> nums={4,2,2,2,4,4,2,2};
    int limit=0;
    printf("%d", longestSubarray(nums, limit));
    return 0;
}
