#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>
#include <wchar.h>

using namespace std;
using LL=long long;

template <typename T, size_t N>
char (&ArraySizeHelper(T (&array)[N]))[N];
#define arraysize(array) (sizeof(ArraySizeHelper(array)))

void func(int* x){
    cout<<x[0];
}

int main(void)
{
    int x[3];
    func(x);
    return 0;
}
