// Leetcode 456
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

bool find132pattern(vector<int>& nums)
{
    size_t N = nums.size();
    if(N<3){return false;}
    int max_right=INT_MIN;
    stack<int> st;
    st.push(nums[N-1]);
    for(auto i=N-2;i>=0;--i){
        if(nums[i]<max_right){
            return true;
        }
        while(!st.empty() && st.top()<nums[i]){
            max_right=st.top();
            st.pop();
        }
        if(nums[i]>max_right){
            st.push(nums[i]);
        }
    }
    return false;
}

int main(void)
{
    return 0;
}
