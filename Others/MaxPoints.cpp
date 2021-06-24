// Leetcode 149
#include <unordered_map>
#include <vector>
using namespace std;

int gcd(int m, int n)
{
    int mod = 0;
    while (n) {
        mod = m % n;
        m = n;
        n = mod;
    }
    return m;
}

inline int HASH(int x, int y)
{
    return x * 20001 + y;
}

int maxPoints(vector<vector<int>>& points)
{
    int N = points.size();
    if (N <= 2) {
        return N;
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (ans > N/2 || ans > (N - i)) {
            break;
        }
        unordered_map<int, int> m;
        for (int j = i + 1; j < N; ++j) {
            int dx = points[i][0] - points[j][0];
            int dy = points[i][1] - points[j][1];
            if (dx == 0) {
                dy = 1;
            } else if (dy == 0) {
                dx = 1;
            } else {
                int gcdXY = gcd(abs(dx), abs(dy));
                dx /= gcdXY;
                dy /= gcdXY;
                if (dy < 0) {
                    dy = -dy;
                    dx = -dx;
                }
                ++m[HASH(dx, dy)];
            }
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            ans = max(ans, it->second);
        }
    }
    return ans;
}
