/* CD18 */
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int solve(int* arr,int n,int num)
{
    int left, right;
    left = right = 0;
    deque<int> maxq, minq;
    int result = 0;
    while(left<n){
        while (right < n)
        {

            while (!maxq.empty() && arr[maxq.back()] <= arr[right])
            {
                maxq.pop_back();
            }
            maxq.push_back(right);
            while (!minq.empty() && arr[minq.back()] >= arr[right])
            {
                minq.pop_back();
            }
            minq.push_back(right);
            if((arr[maxq.front()]-arr[minq.front()])>num)
                break;

            ++right;
        }
        result += right - left;
        if (!maxq.empty() && maxq.front() == left)
        {
            maxq.pop_front();
        }
        if(!minq.empty() && minq.front()==left){
            minq.pop_front();
        }
        ++left;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int n, num;
    cin >> n >> num;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << solve(arr, n, num) << endl;
    return 0;
}
//20 290516-232004 338028 -421441 637677 753499 595611 784268 -106853 -360216 701981 43869 -965250 335771 507555 429251 -945890 -923495 422049 260582 -566803