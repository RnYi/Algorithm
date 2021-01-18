/* leetcode76 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t)
{
    unordered_map<char, int> need, window;
    for(auto ch:t){
        need[ch]++;
    }
    int low,high;
    low = high = 0;//左闭右开区间
    int res_start;
    int res_len = s.length()+1;
    int match_len = 0;
    while (high < s.length())
    {
        char now = s[high];
        high++;
        if (need.count(now) != 0)
        {
            window[now]++;
            if(window[now]==need[now])
                match_len++;
        }

        while(match_len==need.size()){
            if((high-low)<res_len){
                res_len = high - low;
                res_start = low;
            }
            char now = s[low];
            low++;
            if (need.count(now) != 0)
            {
                if(window[now]==need[now])
                    match_len--;

                window[now]--;
            }
        }

    }

    return res_len == s.length() + 1 ? "" : s.substr(res_start, res_len);
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
