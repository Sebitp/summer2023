#include <math.h>
using namespace std;
#include <vector>
#include <queue>


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        
        q.push(root);
        while(!q.empty()){
            int x = q.size();
            vector<int> v;
            for(auto i = 0; i<x; ++i){  
                TreeNode* temp = q.front();
                q.pop();
                

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }   
              
                
                v.push_back(temp->val);
                
            }
            res.push_back(v);
        }
        return res;
    }
};