// Leetcode 1723
#include <algorithm>
#include <functional>
#include <limits.h>
#include <numeric>
#include <stdio.h>
#include <vector>

using namespace std;
bool backtrack(vector<int>& jobs, int* workloads, int idx, int limit,int k)
{
    if (idx >= jobs.size()) {
        return true;
    }
    int cur = jobs[idx];
    for (int i=0;i<k;++i) {
        int& workload = workloads[i];
        if (workload + cur <= limit) {
            workload += cur;
            if (backtrack(jobs, workloads, idx + 1, limit,k)) {
                return true;
            }
            workload -= cur;
        }
        // 如果当前工人未被分配工作，那么下一个工人也必然未被分配工作
        // 或者当前工作恰能使该工人的工作量达到了上限
        // 这两种情况下我们无需尝试继续分配工作
        if (workload == 0 || workload + cur == limit) {
            break;
        }
    }
    return false;
}

bool check(vector<int>& jobs, int k, int limit)
{
    int workloads[12]={0};
    return backtrack(jobs, workloads, 0, limit,k);
}

int minimumTimeRequired(vector<int>& jobs, int k)
{
    sort(jobs.begin(), jobs.end(), greater<int>());
    int lb = jobs[0], ub = accumulate(jobs.begin(), jobs.end(), 0);
    while (lb < ub) {
        int mid = lb+(ub-lb)/2;
        if (check(jobs, k, mid)) {
            ub = mid;
        } else {
            lb = mid + 1;
        }
    }
    return lb;
}

int main(void)
{
    vector<int> jobs = { 1, 2, 4, 7, 8 };
    int k = 2;
    printf("minimumTimeRequired(jobs,k) = %d\n", minimumTimeRequired(jobs, k));
    return 0;
}
