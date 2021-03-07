// Leetcode 678
#include <functional>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

inline bool inbound(int N, int M, int x, int y){
    return x>=0 && x<N && y>=0 && y<M;
}

int kthLargestValue(vector<vector<int>>& matrix, int k)
{
    int N=matrix.size();
    int M=matrix[0].size();
    priority_queue< int, vector<int>, greater<int>> pq;
    int count=0;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(inbound(N, M, i-1, j)){
                matrix[i][j]^=matrix[i-1][j];
            }
            if(inbound(N, M, i, j-1)){
                matrix[i][j]^=matrix[i][j-1];
            }
            if(inbound(N, M, i-1, j-1)){
                matrix[i][j]^=matrix[i-1][j-1];
            }
            if(count<k){
                pq.push(matrix[i][j]);
                ++count;
            }else{
                if(pq.top()<matrix[i][j]){
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
    }
    return pq.top();
}

int main(void)
{
    vector<vector<int>> matrix={
        {5,2},{1,6}
    };
    printf("%d",kthLargestValue(matrix, 3));
    return 0;
}
