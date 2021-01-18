/* Leetcode75 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) 
{
    int size = nums.size();
    if(size==0)
        return;
    int red_index = 0;
    int blue_index = size - 1;
    int cur = 0;
    while(cur<=blue_index)
    {
        if(nums[cur]==0){
            swap(nums[cur++], nums[red_index++]);
        }else if(nums[cur]==2){
            swap(nums[cur], nums[blue_index--]);
        }else{
            ++cur;
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    return 0;
}
