/* Leetcode94 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


vector<int> inorderTraversal(TreeNode* root) 
{

    stack<TreeNode *> s;
    vector<int> ans;

    TreeNode *cur = root;
    while(cur!=NULL || !s.empty()){
        while(cur!=NULL){
            s.push(cur);
            cur = cur->left;
        }

        cur = s.top();
        s.pop();
        ans.push_back(cur->val);
        cur = cur->right;
    }
    return move(ans);
}