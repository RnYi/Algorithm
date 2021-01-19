// Leetcode 721
#include <algorithm>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

int find(vector<int>& parent, int x)
{
    while (x != parent[x]) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void merge(vector<int>& parent, int x, int y)
{
    int px = find(parent, x);
    int py = find(parent, y);
    parent[py] = px;
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
{
    int emailCount = 0;
    unordered_map<string, int> emailToIndex;
    unordered_map<string, string> emailToName;

    for (auto& account : accounts) {
        string& name = account[0];
        for (int i = 1; i < account.size(); ++i) {
            if (emailToIndex.count(account[i]) == 0) {
                emailToIndex[account[i]] = emailCount++;
                emailToName[account[i]] = name;
            }
        }
    }

    vector<int> union_set(emailCount, 0);
    for (int i = 0; i < emailCount; ++i) {
        union_set[i] = i;
    }

    for (auto& account : accounts) {
        string& firstEmail = account[1];
        int firstIndex = emailToIndex[firstEmail];
        for (int i = 2; i < account.size(); ++i) {
            merge(union_set, firstIndex, emailToIndex[account[i]]);
        }
    }

    unordered_map<int, vector<string>> indexToEmails;
    for (auto& [email, index] : emailToIndex) {
        index = find(union_set, index);
        auto& emailList = indexToEmails[index];
        emailList.emplace_back(email);
    }

    vector<vector<string>> result;
    for (auto& [index, emailList] : indexToEmails) {
        sort(emailList.begin(), emailList.end());
        vector<string> accountTmp;
        string& name = emailToName[emailList[0]];
        accountTmp.emplace_back(name);
        for (auto& email : emailList) {
            accountTmp.emplace_back(email);
        }
        result.emplace_back(accountTmp);
    }
    return result;
}

int main()
{
    vector<vector<string>> accounts = {
        { "John", "johnsmith@mail.com", "john_newyork@mail.com" },
        { "John", "johnsmith@mail.com", "john00@mail.com" },
        { "Mary", "mary@mail.com" },
        { "John", "johnnybravo@mail.com" }
    };
    for (auto& account : accountsMerge(accounts)) {
        for (auto& each : account) {
            printf("%s\t",each.c_str());
        }
        printf("\n");
    }
    return 0;
}
