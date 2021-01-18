/*Leetcode127*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int bfs(queue<pair<string,int>>& curQ,unordered_map<string,int>& curVis,unordered_map<string,int>& otherVis,unordered_map<string, vector<string>>& allCombDict){

    string curWord = curQ.front().first;
    int curLevel = curQ.front().second;
    curQ.pop();

    int len = curWord.length();
    for (int i = 0; i < len;++i){
        string tmp = curWord.substr(0, i) + "*" + curWord.substr(i + 1, len);
        for(auto word:allCombDict[tmp]){
            if(curVis[word]==0){
                if(otherVis[word])
                    return curLevel + otherVis[word];

                curVis[word] = curLevel + 1;
                curQ.push(make_pair(word, curLevel + 1));
            }
        }

    }

    return -1;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int size = wordList.size();
    int len = beginWord.size();
    if (size == 0)
        return 0;

    bool flag = false;
    unordered_map<string, vector<string>> allCombDict;

    for (int i = 0; i < size;++i){
        for (int idx = 0; idx < len;++idx){
            string tmp = wordList[i].substr(0, idx) + "*" + wordList[i].substr(idx + 1, len);
            allCombDict[tmp].push_back(wordList[i]);
        }
        if(wordList[i]==endWord){
            flag = true;
        }
    }

    if(!flag)
        return 0;

    queue<pair<string, int>> beginQ, endQ;
    beginQ.push(make_pair(beginWord, 1));
    endQ.push(make_pair(endWord, 1));

    unordered_map<string, int> beginVis, endVis;
    beginVis[beginWord] = 1;
    endVis[endWord] = 1;
    while (!beginQ.empty() && !endQ.empty())
    {
        int ans;

        ans = bfs(beginQ, beginVis, endVis,allCombDict);
        if(ans!=-1)
            return ans;

        ans = bfs(endQ, endVis, beginVis,allCombDict);
        if(ans!=-1)
            return ans;
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << ladderLength(beginWord, endWord, wordList);
    return 0;
}
