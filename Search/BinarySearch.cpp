#include <iostream>
using namespace std;

int binarySearch(int nums[], size_t len, int target)
{
    int left = 0;
    int right = len;
    int mid;
    
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }

    return -1; //无结果则返回-1
}

int left_bound(int nums[], int len, int target)
{
    int left = 0;
    int right = len;
    int mid;
    
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left; //第一个大于等于target的元素的下标
}

int right_bound(int nums[], int len, int target)
{
    int left = 0;
    int right = len;
    int mid;
    
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] > target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left; //第一个大于target的元素的下标
}

int main()
{
    int nums[2] = { 2, 2 };
    int target = 3;
    cout << left_bound(nums, 2, target) << right_bound(nums, 2, target) << endl;
    return 0;
}
