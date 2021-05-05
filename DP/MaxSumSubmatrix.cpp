// Leetcode 363
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
{
    int m = matrix.size();
    int n = matrix[0].size();
    
    int sum[101] = {0};
    int ans=INT_MIN;
    set<int> rec;
    for(int top=1;top<=m;++top){
        // 枚举矩形上边
        memset(sum, 0, sizeof(sum));
        for(int bot=top;bot<=m;++bot){
            // 枚举矩形下边
            rec.clear();
            rec.insert(0);
            int pre_sum=0;
            for(int r=1; r<=n; ++r){
                // 枚举矩形右边
                sum[r]+=matrix[bot-1][r-1]; // 计算第r列的和
                pre_sum+=sum[r];
                auto it = rec.lower_bound(pre_sum-k);
                if(it!=rec.end()){
                    if(*it==pre_sum-k){return k;}
                    ans=max(ans, pre_sum-*it);
                }
                rec.insert(pre_sum);
            }
        }
    }
    return ans;
}

int main(void)
{
    vector<vector<int>> matrix = {
        {5,-4,-3,4},
        {-3,-4,4,5},
        {5,1,5,-4}
    };
    int k=3;
    printf("maxSumSubmatrix(matrix,k) = %d\n", maxSumSubmatrix(matrix,k));
    return 0;
}
