/* CD16 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int len = heights.size();
    if(len==0)
        return 0;
    if(len==1)
        return heights[0];
    stack<int> s;
    int max_area = 0;
    for (int i = 0; i < len;++i)
    {
        while(!s.empty()&&(heights[s.top()]>heights[i])){
            int height = heights[s.top()];
            s.pop();
            int width = i;
            if(!s.empty()){
                width = width - s.top() - 1;
            }
            max_area = max(max_area, height * width);
        }
        s.push(i);
    }

    while(!s.empty()){
        int height = heights[s.top()];
        s.pop();
        int width = len;
        if(!s.empty()){
            width = width - s.top() - 1;
        }
        max_area = max(max_area, height * width);
    }

    return max_area;
}

int solve(vector< vector<int> >& map){
    int n = map.size();
    if(n==0)
        return 0;
    int m = map[0].size();
    if(m==0)
        return 0;
    vector<int> heights(map[0].size(), 0);
    int rtv = 0;
    for (int i = 0; i < n;++i){
        for (int j = 0; j < m;++j){
            if(map[i][j]!=0)
                heights[j]++;
            else
                heights[j] = 0;
        }
        rtv = max(rtv, largestRectangleArea(heights));
    }

    return rtv;
}

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n>>m;
    int i, j;
    vector< vector<int> > map(n, vector<int>(m));
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            cin >> map[i][j];
        }
    }
    cout << solve(map) << endl;
    return 0;
}
