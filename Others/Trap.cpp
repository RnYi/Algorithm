#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int trap_dynamic(vector<int>& height)
{
    int size = height.size();
    if(size==0)
        return 0;
    int *left_max = new int[size];
    int *right_max = new int[size];
    left_max[0] = height[0];
    for (int i = 1; i < size;++i){
        left_max[i] = max(left_max[i - 1], height[i]);
    }
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0;--i){
        right_max[i] = max(right_max[i + 1], height[i]);
    }

    int ans = 0;
    for (int i = 0; i < size;++i){
        ans += min(left_max[i], right_max[i]) - height[i];
    }

    return ans;
}

int trap_stack(vector<int>& height)
{
    int size = height.size();
    if(size==0)
        return 0;
    stack<int> s;
    int index = 0;
    int ans = 0;
    while(index<size){
        while(!s.empty() && height[index]>height[s.top()]){
            int top = s.top();
            s.pop();
            if(s.empty())
                break;
            int bound_height = min(height[index], height[s.top()]) - height[top];
            int distance = index - s.top() - 1;
            ans += bound_height * distance;
        }
        s.push(index);
        ++index;
    }
    return ans;
}

int trap_doubleptr(vector<int>& height)
{
    int size = height.size();
    if(size==0)
        return 0;
    int left_max, right_max;
    int ans = 0;
    left_max = right_max = 0;
    int left, right;
    left = 0;
    right_max = size - 1;
    while(left<right){
        if(height[left]<height[right]){
            height[left] >= left_max ? (left_max = height[left]) : (ans += left_max - height[left]);
            ++left;
        }
        else
        {
            height[right] >= right_max ? (right_max = height[right]) : (ans += right_max - height[right]);
            --right;
        }
    }
    return ans;
}

int trap(vector<int>& height) 
{
    return trap_stack(height);
}

int main(int argc, char const *argv[])
{
    return 0;
}
