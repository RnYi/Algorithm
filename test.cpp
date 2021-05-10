#include <algorithm>
#include <inttypes.h>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

class Solution {
public:
    void getLeafs(TreeNode* root, vector<int>& leafs)
    {
        if(root==nullptr){return;}
        if(root->left==nullptr && root->right==nullptr){
            leafs.emplace_back(root->val);
            return;
        }
        getLeafs(root->left, leafs);
        getLeafs(root->right, leafs);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> leafs1;
        getLeafs(root1, leafs1);
        vector<int> leafs2;
        getLeafs(root2, leafs2);
        int len1 = leafs1.size();
        int len2 = leafs2.size();
        if(len1!=len2){return false;}
        for(int i=0; i<len1;++i){
            if(leafs1[i]!=leafs2[i]){return false;}
        }
        return true;
    }
};

int main(void)
{
    return 0;
}
