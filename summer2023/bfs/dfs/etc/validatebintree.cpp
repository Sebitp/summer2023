#include <limits.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root,INT_MIN,INT_MAX);
    }
    bool valid(TreeNode* node, int l, int r){
        if(!node) return true;
        if (!(node->val > l && node->val < r)) return false;
        bool l_node = valid(node->left,l,node->val);
        bool r_node = valid(node->right,node->val,r);
        return l_node && r_node;
    }
};