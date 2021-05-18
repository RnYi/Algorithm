#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include <vector>
using namespace std;

int countTriplets(vector<int>& arr)
{
    int N = arr.size();
    unordered_map<int, int> cnt, total;
    int ans = 0;
    int s = 0;
    for (int k = 0; k < N; ++k) {
        int val = s ^ arr[k];
        if (cnt.count(val)) {
            ans += cnt[val] * k - total[val];
        }
        ++cnt[s];
        total[s] += k;
        s = val;
    }
    return ans;
}
int main(void)
{
    vector<int> arr = { 2, 3, 1, 6, 7 };
    printf("countTriplets(arr) = %d\n", countTriplets(arr));
    return 0;
}
