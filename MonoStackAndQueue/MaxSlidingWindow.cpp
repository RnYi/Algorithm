/*剑指offer59*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    int n = nums.size();
    if (n == 0)
        return {};
    deque<int> max_queue;
    vector<int> result(n - k + 1, 0);
    int result_index = 0;
    int f, b;
    f = b = 0;
    while(b<k){
        while(!max_queue.empty()&&max_queue.back()<nums[b]){
            max_queue.pop_back();
        }
        max_queue.push_back(nums[b]);
        ++b;
    }
    --b;
    while (b < n)
    {
        result[result_index] = max_queue.front();
        ++result_index;
        if(nums[f]==max_queue.front()){
            max_queue.pop_front();
        }
        ++f;
        ++b;
        if(b<n){
            while (!max_queue.empty() && max_queue.back() < nums[b])
            {
                max_queue.pop_back();
            }
            max_queue.push_back(nums[b]);
        }
        
    }
}

int main(int argc, char const *argv[])
{
    return 0;
}
