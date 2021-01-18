#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int mergeSort(vector<int>& nums,vector<int>&tmp, int low,int high)
{
    if(low>=high)
        return 0;
    int mid = (low + high) / 2;
    int revpair = mergeSort(nums, tmp, low, mid) + mergeSort(nums, tmp, mid + 1, high);
    int l, r,t;
    l = low;
    r = mid + 1;
    t = low;
    while(l<=mid&&r<=high){
        if(nums[l]<=nums[r]){
            tmp[t] = nums[l];
            revpair += r - mid - 1;
            l++;
            t++;
        }else{
            tmp[t] = nums[r];
            r++;
            t++;
        }
    }
    while (l<=mid)
    {
        tmp[t] = nums[l];
        l++;
        t++;
        revpair += r - mid - 1;
    }
    while (r<=high)
    {
        tmp[t] = nums[r];
        r++;
        t++;
    }

    copy(tmp.begin() + low, tmp.begin() + high+1, nums.begin() + low);
    return revpair;
}

int reversePairs(vector<int>& nums) 
{
    vector<int> tmp(nums.size());
    return mergeSort(nums, tmp, 0, nums.size() - 1);
}