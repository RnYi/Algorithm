// Leetcode 1486
#include <stdio.h>
#include <vector>

using namespace std;

int sumXor(int x)
{
    // sumXor(x) = 0 ^ 1 ^ 2 ^ ... ^ x
    //
    //              x,                         x=4k
    //              (x-1) ^ x,                 x=4k+1
    // sumXor(x) =  (x-2) ^ (x-1) ^ x,         x=4k+2
    //              (x-3) ^ (x-2) ^ (x-1) ^ x, x=4k+3
    //
    // 因为有4i ^ (4i+1) ^ (4i+2) ^ (4i+3) = 0
    //
    //              x,   x=4k
    //              1,   x=4k+1
    // sumXor(x) =  x+1, x=4k+2
    //              0,   x=4k+3
    int mod4 = x % 4;
    if (mod4 == 0) {
        return x;
    }
    if (mod4 == 1) {
        return 1;
    }
    if (mod4 == 2) {
        return x + 1;
    }
    return 0;
}

int xorOperation(int n, int start)
{
    // ans = start ^ (start+2i) ^ (start+4i) ^ ... ^ (start+2(n-1))
    // s = start / 2
    // e 为ans最低位
    // ans = (s ^ (s+1) ^ (s+2) ^ ... ^ (s+n-1)) * 2 + e
    int s = start >> 1;
    int e = n & start & 1;
    int ans = sumXor(s - 1) ^ sumXor(s + n - 1);
    return ans << 1 | e;
}

int main(void)
{
    int n = 10;
    int start = 5;
    printf("xorOperation(n, start)= %d\n", xorOperation(n, start));
    return 0;
}
