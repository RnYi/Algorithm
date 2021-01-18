/*CD57*/
#include <iostream>

using namespace std;

int NFactZeroNums(int n)
{
    /* ans=n/2 + n/4 + n/8 + ... + n/2^i */
    if(n<1)
        return -1;
    int ans = 0;
    while(n!=0){
        n >>= 1;
        ans += n;
    }
    return ans;
}

int NFactZeroNums_2(uint32_t n)
{
    int count_one = 0;
    uint32_t tmp = n;
    while (n != 0)
    {
        n = n & (n - 1);
        ++count_one;
    }
    return (tmp - count_one);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << NFactZeroNums(n) << endl;
    cout << NFactZeroNums_2(n) << endl;
    return 0;
}
