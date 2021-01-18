#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void rotate(vector<vector<int>>& matrix) 
{
            int N = matrix.size();
    if(N==0)
        return;
    int M = matrix[0].size();
    if(N!=M)
        return;
    int levels = N / 2;
    for (int level = 0; level < levels;++level){
        int len = N - 2 * level;
        for (int i = 0; i < len-1;++i){//len-1
            int tmp = matrix[level][level+i];
            matrix[level][level + i] = matrix[level + len - 1 - i][level];
            matrix[level + len - 1 - i][level] = matrix[level + len - 1][level + len - 1 - i];
            matrix[level + len - 1][level + len - 1 - i] = matrix[level + i][level + len - 1];
            matrix[level + i][level + len - 1] = tmp;
        }
    }
    return;
}