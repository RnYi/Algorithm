#include <functional>
#include <iostream>
#include <queue>
#include <typeinfo>
#include <utility>
#include <vector>
using namespace std;

inline bool inBound(int m, int n, int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n;
}

bool isToeplitzMatrix(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    // 0,0
    int sx, sy;
    sx = m - 1;
    sy = 0;
    while (sy!=n) {
        cout<<"sx: "<<sx<<'\t'<<"sy: "<<sy<<endl;
        int val = matrix[sx][sy];
        int x = sx, y = sy;
        while (inBound(m, n, x, y)) {
            if (matrix[x][y] != val) {
                return false;
            }
            ++x;
            ++y;
        }
        if (sx != 0) {
            --sx;
        } else {
            ++sy;
        }
    }
    return true;
}

int main(void)
{
    vector<vector<int>> mat = {
        {1,2}, {2,2}
    };
    printf("isToeplitzMatrix(mat) = %d\n", isToeplitzMatrix(mat));
    return 0;
}
