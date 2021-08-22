#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>
#include <wchar.h>

using namespace std;
using LL=long long;

int main(void)
{
    int arr0[2][2]={{0,1},{2,3}};
    int arr1[2][2]={};
    memcpy(arr1, arr0, sizeof(arr0));
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            cout<<arr1[i][j]<<'\t';
        }
    }

    return 0;
}
