// Leetcode 316
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <string>
#define INDEX(ch) (ch - 'a')
using namespace std;
string removeDuplicateLetters(string& s)
{
    bitset<26> HAS;
    int counts[26] = { 0 };
    for (auto& ch : s) {
        ++counts[INDEX(ch)];
    }
    string rtv = "";
    for (auto& ch : s) {
        if (HAS[INDEX(ch)]) {
            --counts[INDEX(ch)];
            continue;
        }
        while (!rtv.empty() && rtv.back() > ch && counts[INDEX(rtv.back())] > 1) {
            --counts[INDEX(rtv.back())];
            HAS.reset(INDEX(rtv.back()));
            rtv.pop_back();
        }
        HAS.set(INDEX(ch));
        rtv.push_back(ch);
    }
    return rtv;
}
int main()
{
    string str = "abacb";
    string rst = removeDuplicateLetters(str);
    printf("%s", rst.c_str());
    return 0;
}
