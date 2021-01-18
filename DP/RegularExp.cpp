/* 剑指offer20 */
#include <iostream>
#include <cmath>
#include <string>
#include<unordered_map>
using namespace std;
bool isMatch(string& s,string& p,int index_s, int index_p,short** hasMatched)
{
    if(index_s<s.length()&&index_p<p.length()){
        if(hasMatched[index_s][index_p]!=0)
            return hasMatched[index_s][index_p];
    }
    if (index_p >= p.length())
        return index_s >= s.length();
    bool first = false;
    bool ans;
    if (index_s < s.length())
        first = p[index_p] == '.' || p[index_p] == s[index_s];

    if (p.length() > index_p + 1 && p[index_p + 1] == '*'){
            ans= (first&&isMatch(s, p, index_s + 1, index_p,hasMatched))||isMatch(s, p, index_s, index_p + 2,hasMatched);
    }else{
        if(first)
            ans= isMatch(s, p, index_s + 1, index_p + 1,hasMatched);
        else
            ans = false;
    }
    if(index_s<s.length()&&index_p<p.length())
     hasMatched[index_s][index_p]=ans;

    return ans;
}
bool isMatch(string s, string p)
{
    int s_len = s.length();
    int p_len = p.length();
    short **hasMatched = new short *[s_len];
    for (int i = 0; i < s_len;++i){
        hasMatched[i] = new short[p_len]();
    }

        return isMatch(s, p, 0, 0,hasMatched);
}

int main()
{
    cout<<isMatch("","a*b*c*");
    return 0;
}