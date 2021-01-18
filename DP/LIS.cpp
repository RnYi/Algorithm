#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int right_bound(int nums[], int len, int target)
{
    int left = 0;
    int right = len - 1;
    int mid;
    while(left<=right)
    {
        mid = left + (right - left) / 2;
        if(nums[mid]>target)
        {
            right = mid - 1;
        }
        else if (nums[mid]<=target)
        {
            left = mid + 1;
        }
    }

    return left;//第一个大于target的元素的下标
} 

void largestIncreaseSubseq(int* arr,int n)
{
    int *minTail = new int[n]();
    int *maxLens = new int[n];
    minTail[0] = arr[0];
    for (int i = 0; i < n;++i){
        maxLens[i] = 1;
    }
    int len = 1;
    for (int i = 1; i < n;++i){
        int index = right_bound(minTail, len, arr[i]);
        if(index==len){
            ++len;
        }
        minTail[index] = arr[i];
        maxLens[i] = index+1;
    }
    int next = numeric_limits<int>::max();
    int cur_index = n-1;
    for (int i = len - 1; i >= 0; --i)
    {
        for (int j = cur_index; j >= 0;--j){
            if(arr[j]<next && maxLens[j]==i+1){
                minTail[i] = arr[j];
                cur_index = j-1;
                next = minTail[i];
                break;
            }
        }
    }

    for (int i = 0; i < len;++i){
        cout << minTail[i] << ' ';
    }

    delete minTail;
    delete maxLens;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n;++i){
        cin >> arr[i];
    }
    largestIncreaseSubseq(arr, n);
    return 0;
}
