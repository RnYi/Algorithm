/* CD21 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

long smallSum_merge(vector<int>& arr,vector<int>& tmp,int low,int high){
    if(low>=high){
        return 0;
    }
    int mid = (low + high) / 2;
    long result = smallSum_merge(arr, tmp, low, mid) + smallSum_merge(arr, tmp, mid + 1, high);
    int l = low;
    int h = mid+1;
    int t = low;
    while(l<=mid&&h<=high){
        if(arr[l]<=arr[h]){
            result += arr[l]*(high-h+1);
            tmp[t] = arr[l];
            ++l;
            ++t;
        }else{
            tmp[t] = arr[h];
            ++h;
            ++t;
        }
    }
    while(l<=mid){
        tmp[t] = arr[l];
        ++l;
        ++t;
    }
    while(h<=high){
        tmp[t] = arr[h];
        ++h;
        ++t;
    }
    for (int i = low; i <= high;++i){
        arr[i] = tmp[i];
    }
        return result;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    vector<int> tmp(n);
    cout << smallSum_merge(arr, tmp, 0, n - 1) << endl;
    return 0;
}
