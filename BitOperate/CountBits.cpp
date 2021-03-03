// Leetcode 338
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> countBits_1(int num)
{
    vector<int> bits(num+1);
    int highBit=0;
    for(int i=1;i<=num;++i){
        if((i&(i-1))==0){
            highBit=i;
        }
        bits[i]=bits[i-highBit]+1;
    }
    return bits;
}

vector<int> countBits_2(int num)
{
    vector<int> bits(num+1);
    for(int i=1;i<=num;++i){
        bits[i]=bits[i>>1]+i&2;
    }
    return bits;
}

vector<int> countBits_3(int num)
{
    vector<int> bits(num+1);
    for(int i=1;i<=num;++i){
        bits[i]=bits[i&(i-1)]+1;
    }
    return bits;
}

vector<int> countBits(int num)
{
    return countBits_1(num);
}

int main(void)
{
    int num=5;
    for(auto& each:countBits(num)){
        printf("%d\t",each);
    }
    return 0;
}

