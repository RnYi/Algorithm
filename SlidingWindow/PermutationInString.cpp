/* Leetcode567 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    unordered_map<char,int> window,need;
    for(auto ch:s1)
        need[ch]++;

    int low, high, valid;
    low = high = valid = 0;
    while(high<s2.length()){
        char now = s2[high];
        high++;
        if(need.count(now)!=0){
            window[now]++;
            if(window[now]==need[now])
                valid++;
        }

        while(valid==need.size()){
            if((high-low)==s1.length()){
                return true;
            }

            char now = s2[low];
            low++;
            
            if(need.count(now)!=0){
                if(window[now]==need[now])
                    valid--;

                window[now]--;
            }
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
