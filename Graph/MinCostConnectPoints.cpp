// Leetcode 1584
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    bool merge(int x, int y)
    {
        int fx = find(x);
        int fy = find(y);

        if (fx == fy) {
            return false;
        }
        if (rank[fx] < rank[fy]) {
            swap(fx, fy);
        }
        rank[fx] += rank[fy];
        parent[fy] = fx;
        return true;
    }
};

struct Edge {
    int x, y, len;
    Edge(int x, int y, int len)
        : x(x)
        , y(y)
        , len(len)
    {
    }
};

int minCostConnectPoints_Kruskal(vector<vector<int>>& points)
{
    auto dis = [&](int x, int y) {
        return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
    };

    vector<Edge> edges;
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i + 1; j < points.size(); ++j) {
            edges.emplace_back(i, j, dis(i, j));
        }
    }

    DisjointSet ds(points.size());
    sort(edges.begin(), edges.end(), [](Edge& ea, Edge& eb) { return ea.len < eb.len; });
    int cost = 0;
    int num = 1;
    for (auto& edge : edges) {
        if (ds.merge(edge.x, edge.y)) {
            ++num;
            cost += edge.len;
            if (num == points.size()) {
                break;
            }
        }
    }

    return cost;
}

int main()
{
    return 0;
}
