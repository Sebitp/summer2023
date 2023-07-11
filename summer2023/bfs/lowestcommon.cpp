using namespace std;
#include <cstdlib>
//this is lowest common binary tree not search tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int nodec = 0;
        nodec++;
        if(root == nullptr) {
            return nullptr;
        }
        if(root == p || root == q) return root;

        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);

        if(l && r) return root;
        if(l) return l;
        if(r) return r;
        return nullptr;
        
        
    }
};