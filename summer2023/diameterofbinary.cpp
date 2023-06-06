using namespace std;
#include <algorithm>

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
    int diameterOfBinaryTree(TreeNode* root) {
        int length = 0;
        heightCount(root,length);
        return length;

    }
    int heightCount(TreeNode* root, int &length){
        if (!root) return 0;
        int left = heightCount(root->left, length);
        int right = heightCount(root->right, length);
        length = max(length,left+right);
        return max(left,right)+1;
    }
};  