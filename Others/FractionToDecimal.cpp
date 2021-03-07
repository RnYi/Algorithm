// Leetcode 166
#include <stdio.h>
#include <string>
#include<unordered_map>
using namespace std;

string fractionToDecimal(int numerator, int denominator)
{
    long long num=numerator;
    long long denom=denominator;
    string ans;
    unordered_map<long long,int> record;
    if(num*denom<0){
        ans.append("-");
    }
    num=abs(num);
    denom=abs(denom);
    long long tmp;
    long long res;
    tmp=num/denom;
    res=num%denom;
    ans.append(to_string(tmp));
    if(res==0){
        return ans;
    }
    ans.append(".");
    res=res*10;
    while(res!=0){
        if(record.find(res)!=record.end()){
            int s_idx=record[res];
            string n_ans="";
            n_ans.append(ans.substr(0,s_idx));
            n_ans.append("(");
            n_ans.append(ans.substr(s_idx,ans.size()));
            n_ans.append(")");
            ans=n_ans;
            break;
        }
        tmp=res/denom;
        int index=ans.size();
        record[res]=index;
        ans.append(to_string(tmp));
        res=res%denom;
        res*=10;
    }
    return ans;
}
    
int main(void)
{
    int numerator=1;
    int denominator=6;
    printf("%s",fractionToDecimal(numerator, denominator).c_str());
    return 0;
}
