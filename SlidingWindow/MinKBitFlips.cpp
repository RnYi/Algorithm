// Leetcode 995
#include <stdio.h>
#include <vector>
using namespace std;

int minKBitFlips(vector<int>& A, int K)
{
    int size = A.size();
    vector<int> diff(size);
    int ans = 0;
    int revCnt = 0;
    for (int i = 0; i < size; ++i) {
        revCnt += diff[i];
        if ((revCnt + A[i]) % 2 == 0) {
            if (i + K > size) {
                return -1;
            }
            if (i + K != size) {
                --diff[i + K];
            }
            ++revCnt;
            ++ans;
        }
    }
    return ans;
}

int main()
{
    vector<int> A { 1, 1, 0 };
    int K = 2;
    printf("%d", minKBitFlips(A, K));
    return 0;
}
