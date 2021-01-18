#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> topSort(vector<int>& items, vector<int>& indeg, vector<vector<int>>& graph)
{
    queue<int> Q;
    for(auto& item:items){
        if(indeg[item]==0){
            Q.emplace(item);
        }
    }

    vector<int> result;
    int tmp;
    while(!Q.empty()){
        tmp=Q.front();
        Q.pop();
        result.emplace_back(tmp);

        for(auto& item:graph[tmp]){
            if(--indeg[item]==0){
                Q.emplace(item);
            }
        }
    }

    return result.size()==items.size()?result:vector<int>{};
}

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems)
{
    vector<vector<int>> groupItem(n+m);
    
    vector<vector<int>> groupGraph(n+m);
    vector<int> groupIndeg(n+m,0);
    
    vector<vector<int>> itemGraph(n);
    vector<int> itemIndeg(n,0);

    vector<int> id(n+m);
    for(int i=0;i<n+m;++i){
        id[i]=i;
    }

    int leftId=m;
    for(int i=0;i<n;++i){
        if(group[i]==-1){
            group[i]=leftId++;
        }
        groupItem[group[i]].emplace_back(i);
    }

    for(int i=0;i<n;++i){
        int curGroupId=group[i];
        for(auto& beforeItem:beforeItems[i]){
            int beforeItemGroupId=group[beforeItem];
            if(curGroupId==beforeItemGroupId){
                itemGraph[beforeItem].emplace_back(i);
                itemIndeg[i]++;
            }else{
                groupGraph[beforeItemGroupId].emplace_back(curGroupId);
                groupIndeg[curGroupId]++;
            }
        }
    }

    auto groupTopSort=topSort(id, groupIndeg, groupGraph);
    if(groupTopSort.size()==0){
        return vector<int>{};
    }

    vector<int> result;
    for(auto& eachGroup:groupTopSort){
        if(groupItem[eachGroup].size()==0){
            continue;
        }
        auto itemTopSort=topSort(groupItem[eachGroup], itemIndeg, itemGraph);
        if(itemTopSort.size()==0){
            return vector<int>{};
        }else {
            for(auto& item:itemTopSort){
                result.emplace_back(item);
            }
        }
    }

    return result;
}


int main()
{
    int n=8,m=2;
    vector<int> group={-1,-1,1,0,0,1,0,-1};
    vector<vector<int>> beforeItems={{},{6},{5},{6},{3,6},{},{},{}};
    for(auto& item:sortItems(n, m, group, beforeItems)){
        printf("%d,",item);
    }
    return 0;
}
