// Leetcode 395
#include <stdio.h>
#include <array>
#include <string>
using namespace std;

int longestSubstring(string s, int k)
{
    int ans=0;
    for(int t=1;t<=26;++t){
        int left=0;
        int right=0;
        int total=0;
        int sum=0;
        array<int, 26> cnt={0};
        while(right<s.length()){
            char ch=s[right++];
            int idx=ch-'a';
            cnt[idx]++;
            if(cnt[idx]==1){
                ++total;
            }
            if(cnt[idx]==k){
                ++sum;
            }

            while(total>t){
                ch=s[left++];
                idx=ch-'a';
                cnt[idx]--;
                if(cnt[idx]==0){--total;}
                if(cnt[idx]==k-1){--sum;}
            }
            if(total==sum){ans=max(ans,right-left);}
        }
    }
    return ans;
}

int main(void)
{
    string s="aaabb";
    int k=3;
    printf("%d",longestSubstring(s, k));
    return 0;
}
