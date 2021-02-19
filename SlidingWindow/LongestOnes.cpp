// Leetcode 1004
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

int longestOnes(vector<int>& A, int K)
{
    int N=A.size();
    int lsum=0; int rsum=0;
    int left=0; int right=0;
    int ans=0;
    while(right<N){
        rsum+=A[right]^1;
        while(lsum<rsum-K){
            lsum+=A[left]^1;
            ++left;
        }
        ans=max(ans, right-left+1);
        ++right;
    }
    return ans;
}

int main()
{
    vector<int> A = { 0, 0, 0, 1 };
    int K = 4;
    printf("%d", longestOnes(A, K));
    return 0;
}

