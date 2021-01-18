/* Leetcode22 */
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void backtrace(int left,int right,int n,string& cur,vector<string>& ans){
    if(cur.length()==2*n){
        ans.push_back(cur);
        return;
    }
    if(left<n){
        cur.push_back('(');
        backtrace(left + 1, right, n, cur, ans);
        cur.pop_back();
    }
    if(right<left){
        cur.push_back(')');
        backtrace(left, right + 1, n, cur, ans);
        cur.pop_back();
    }
}

vector<string> generateParenthesis(int n) 
{
    string cur;
    vector<string> ans;
    backtrace(0, 0, n, cur, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
 
    return 0;
}
