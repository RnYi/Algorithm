/* Leetcode94 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

int maxGain(TreeNode* root ,int& maxsum){
    if(root==NULL)
        return 0;
    int leftGain = max(maxGain(root->left, maxsum),0);
    int rightGain = max(maxGain(root->right, maxsum), 0);

    maxsum = max(maxsum, root->val + leftGain + rightGain);

    return root->val + max(leftGain, rightGain);
}

int maxPathSum(TreeNode* root) 
{
    int maxsum = INT32_MIN;
    maxGain(root, maxsum);
    return maxsum;
}

int main(int argc, char const *argv[])
{

    return 0;
}
