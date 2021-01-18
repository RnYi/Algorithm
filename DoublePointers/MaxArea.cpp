/* Leetcode11 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) 
{
    int len = height.size();
    int max_area = 0;
    int left, right;
    left = 0;
    right = len - 1;
    while (left<right){
        max_area = min(height[left], height[right]) * (right - left);
        if(height[left]<height[right]){
            ++left;
        }else{
            --right;
        }
    }
    return max_area;
}

int main(int argc, char const *argv[])
{
    return 0;
}
