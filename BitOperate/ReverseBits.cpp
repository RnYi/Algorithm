// Leetcode 190
#include <algorithm>
#include <stdio.h>
#include <stdint.h>
using namespace std;

uint32_t reverseBits(uint32_t n) 
{
    n = (n >> 1 & 0x55555555) | (n & 0x55555555) >> 1;
    n = (n >> 1 & 0x33333333) | (n & 0x33333333) >> 1;
    n = (n >> 1 & 0x0f0f0f0f) | (n & 0x0f0f0f0f) >> 1;
    n = (n >> 1 & 0x00ff00ff) | (n & 0x00ff00ff) >> 1;
    n = n << 16 | n >> 16;

    return n;
}

int main(void)
{
    return 0;
}
