/* Leetcode3 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> window;

    int low, high;
    low = high = 0;
    int longest_len = 0;
    while (high < s.length())
    {
        char now_high = s[high];
        high++;        
        window[now_high]++;

        while(window[now_high]>1){
            char now_low = s[low];
            low++;
            window[now_low]--;
        }
        longest_len = max(longest_len, high - low);
    }

    return longest_len;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
