// Leetcode 399
#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int findf(vector<int>& f, vector<double>& w, int x)
{
    if (f[x] != x) {
        int father = findf(f, w, f[x]);
        w[x] = w[x] * w[f[x]];
        f[x] = father;
    }
    return f[x];
}

void merge(vector<int>& f, vector<double>& w, int x, int y, double val)
{
    int fx = findf(f, w, x);
    int fy = findf(f, w, y);
    f[fx] = fy;
    w[fx] = val * w[y] / w[x];
}

vector<double> calcEquation(
    vector<vector<string>>& equations,
    vector<double>& values,
    vector<vector<string>>& queries)
{
    int neqs = equations.size();
    int nvars = 0;
    unordered_map<string, int> variables;

    for (auto& eq : equations) {
        if (variables.find(eq[0]) == variables.end()) {
            variables[eq[0]] = nvars++;
        }
        if (variables.find(eq[1]) == variables.end()) {
            variables[eq[1]] = nvars++;
        }
    }

    vector<int> f(nvars);
    vector<double> w(nvars, 1.0);
    for (int i = 0; i < nvars; ++i) {
        f[i] = i;
    }
    for (int i = 0; i < neqs; ++i) {
        int a = variables[equations[i][0]];
        int b = variables[equations[i][1]];
        merge(f, w, a, b, values[i]);
    }
    vector<double> ret;
    for (auto& q : queries) {
        double result = -1.0;
        if (variables.find(q[0]) != variables.end() && variables.find(q[1]) != variables.end()) {
            int a = variables[q[0]];
            int b = variables[q[1]];
            int fa = findf(f, w, a);
            int fb = findf(f, w, b);
            if (fa == fb) {
                result = w[a] / w[b];
            }
        }
        ret.push_back(result);
    }
    return ret;
}

int main(int argc, char* argv[])
{
    return 0;
}
