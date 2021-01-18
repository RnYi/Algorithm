/*剑指offer26*/
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

bool isContain(TreeNode* A, TreeNode* B){
    if(B==NULL)
        return true;
    if(A==NULL)
        return false;
    if (A->val == B->val)
        return isContain(A->left, B->left) && isContain(A->right, B->right);
    else
        return false;
}

bool isSubStructure(TreeNode* A, TreeNode* B) {
    if(A==NULL||B==NULL)
        return false;
    return isContain(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
}