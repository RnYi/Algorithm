// Leetcode 678
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

void init(const string& str, vector<vector<bool>>& pa)
{
    int N=str.length();
    for(int j=1;j<N;++j){
        for(int i=j-1;i>=0;--i){
            pa[i][j]=(str[i]==str[j]) && pa[i+1][j-1];
        }
    }
}

void backtrace(int start, const string& str, vector<vector<bool>>& pa, vector<string>& cur, vector<vector<string>>& ans)
{
    int N=str.length();
    if(start==N){
        ans.push_back(cur);
        return;
    }
    for(int end=start;end<N;++end){
        if(!pa[start][end]){
            continue;
        }
        cur.push_back(str.substr(start,end-start+1));
        backtrace(end+1, str, pa, cur, ans);
        cur.pop_back();
    }
}

vector<vector<string>> partition(string s)
{
    int N=s.length();
    vector<vector<bool>> pa(N,vector<bool>(N,true));
    init(s, pa);
    vector<vector<string>> ans;
    vector<string> cur;
    backtrace(0, s, pa, cur, ans);
    return ans;
}

int main(void)
{
    string s="aab";
    auto ans=partition(s);
    for(auto& part:ans){
        for(auto& each:part){
            printf("%s\t",each.c_str());
        }
            printf("\n");
    }
    return 0;
}
