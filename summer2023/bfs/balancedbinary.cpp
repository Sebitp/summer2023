#include <math.h>
using namespace std;
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
    bool isBalanced(TreeNode* root) {
        bool result = true;
        heightCount(root, result);
        return result;
    }
    int heightCount(TreeNode* root, bool& result){
        if(!root || !result) return 0;

        int l = heightCount(root->left, result);
        int r = heightCount(root->right, result);
        if (abs(l-r) > 1){
            result = false;
        }
        return max(l,r) + 1;
    }
};
