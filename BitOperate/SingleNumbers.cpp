/* 剑指offer56 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> singleNumbers(vector<int>& nums)
{
    int allxor = 0;
    for(auto num:nums){
        allxor ^= num;
    }
    int div = allxor & (-allxor);
    int a, b;
    a = b = 0;
    for(auto num:nums){
        if((div&num)==0){
            a ^= num;
        }else
            b ^= num;
    }

    return {a, b};
}