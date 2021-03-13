// Leetcode 732
#include <algorithm>
#include <stdio.h>
using namespace std;

// 线段树离散处理 复杂度O(log(1e9)*n)
const int MX = 1e5 + 5;   // 数据量
const int M = 1e9;        // 数据范围

class MyCalendarThree {
public:
    int ls[MX], rs[MX], sum[MX], lz[MX];  // ls rs分别是左子树右子树的idx
    int cnt, root;

    MyCalendarThree() {
        ls[0] = rs[0] = sum[0] = lz[0] = 0;
        cnt = 0;
        root = ++cnt;
        init_node(root);
    }

    void init_node(int rt) {
        ls[rt] = rs[rt] = sum[rt] = lz[rt] = 0;
    }

    void pushUp(int rt) {
        int l = ls[rt], r = rs[rt];
        sum[rt] = max(sum[l] + lz[l], sum[r] + lz[r]);
    }

    void update(int L, int R, int l, int r, int& rt) {
        if (rt == 0) {
            rt = ++cnt;
            init_node(rt);
        }
        if (L <= l && R >= r) {
            lz[rt]++;
            return;
        }
        int m = (l + r) >> 1;
        if (L <= m) update(L, R, l, m, ls[rt]);
        if (R > m) update(L, R, m + 1, r, rs[rt]);
        pushUp(rt);
    }
    
    int book(int start, int end) {
        if (start < end) {
            update(start, end - 1, 0, M, root);
        }
        return sum[root] + lz[root];
    }
};

