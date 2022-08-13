/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            for(int i = 0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                int index = flag ? i : (size-i-1);
                level[index] = temp->val;
                
                if(temp->left!=nullptr) q.push(temp->left);
                if(temp->right!=nullptr) q.push(temp->right);
            }
            flag = !flag;
            res.push_back(level);
        }
        return res;
    }
};