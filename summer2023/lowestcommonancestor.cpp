using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = root;
        if (p->val > root->val && q->val > root->val){
            lca = root->right;
            
            return lowestCommonAncestor(lca, p, q);
        } else if (p->val < root->val && q->val < root->val){
            lca = root->left;
            
            return lowestCommonAncestor(lca, p, q);
        } else return root;
        // if (p->val == root->val){
        //     return p;
        // } else if (q->val == root->val){
        //     return q;
        // } else return lca;
    }

};