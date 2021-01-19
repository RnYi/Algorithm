// Leetcode 207
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<vector<int>> adj(numCourses,vector<int>());
    vector<int> indeg(numCourses,0);

    for(auto& edge:prerequisites){
        adj[edge[1]].push_back(edge[0]);
        ++indeg[edge[0]];
    }
    
    queue<int> q;
    for(int i=0;i<numCourses;++i){
        if(indeg[i]==0){
            q.push(i);
        }
    }

    int count=0;
    while(!q.empty()){
        int pre=q.front();
        q.pop();
        for(auto& node:adj[pre]){
            --indeg[node];
            if(indeg[node]==0){
                q.push(node);
            }
        }
        ++count;
    }
    return count==numCourses;
}

int main()
{
    int numCourses=2;
    vector<vector<int>> prerequisites={{ {1,0} }};
    printf("%d",canFinish(numCourses, prerequisites));
    return 0;
}
