// Leetcode 28
#include <crtdefs.h>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int strStr_Sunday(const string& target, const string& pattern)
{
    int N = target.length();
    int M = pattern.length();
    // 假设字符串仅包含小写英文字母
    vector<int> offset(26, M+1);
    for(int i =0; i<M;++i){
        offset[pattern[i]-'a'] = M-i;
    }
    int idx=0;
    while(idx<=N-M){
        bool match=true;
        for(int i=0;i<M;++i){
            if(target[idx+i]!=pattern[i]){
                match=false;
                break;
            }
        }
        if(match){
            return idx;
        }else{
            if(idx+M>=N){return -1;}
            idx+=offset[target[idx+M]-'a'];
        }
    }
    return -1;
}

int strStr(string haystack, string needle)
{
    return strStr_Sunday(haystack, needle);
}

int main(void)
{
    return 0;
}
