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
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> v(sz);

            for(int i = 0;i < sz; i++){
                TreeNode* temp = q.front();
                q.pop();

                int row = leftToRight ? i : sz - i - 1;
                v[row] = temp->val;
                
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
            leftToRight = !leftToRight;
            result.push_back(v);
        }
        return result;
    }
};