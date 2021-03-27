// Leetcode 456
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

int minMoves(vector<int>& nums, int limit)
{
    vector<int> diff(2*limit+2,0);
    size_t N=nums.size();
    for(size_t i=0;i<N/2;++i){
        int A=nums[i];
        int B=nums[N-1-i];
        size_t l=2; size_t r=2*limit;
        diff[l]+=2; diff[r+1]-=2;

        l=1+min(A,B); r=limit+max(A,B);
        diff[l]+=-1; diff[r+1]-=-1;

        l=A+B; r=A+B;
        diff[l]+=-1; diff[r+1]-=-1;
    }
    int ans=N;
    int sum=0;
    for(auto& e:diff){
        sum+=e;
        ans=min(ans,sum);
    }
    return ans;
}

int main(void)
{
    return 0;
}
