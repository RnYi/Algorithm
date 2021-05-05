// Leetcode 28
#include <crtdefs.h>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int strStr_KMP(const string& target, const string& pattern)
{
    int N = target.length();
    int M = pattern.length();
    // PMT为部分匹配表，PMT[i]为needle[i]的最大相同前后缀长度,
    // PMT整体后移一位即为next数组，
    vector<int> next(M+1);
    next[0]=-1;
    int i = 0;
    int j = -1;
    // 初始化next数组，实际上就是needle与自身前缀匹配的过程
    while(i<M){
        if(j==-1 || pattern[i]==pattern[j]){
            ++i;
            ++j;
            next[i]=j;
        }else{
            j=next[j];
        }
    }
    i=j=0;
    // 进行匹配
    while(i<N && j<M){
        if(j==-1 || target[i]==pattern[j]){
            ++i;
            ++j;
        }else{
            // 不匹配时，j=PMT[j-1]=next[j]
            j = next[j];
        }
    }
    if(j==M){
        return i-j;
    }else{
        return -1;
    }
}

int strStr(string haystack, string needle)
{
    return strStr_KMP(haystack, needle);
}

int main(void)
{
    return 0;
}
