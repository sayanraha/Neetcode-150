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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        heightTree(root, diameter);
        return diameter;
    }
private:
    int heightTree(TreeNode* root, int &diameter){
        if(root == NULL)return 0;

        int leftH = heightTree(root->left,diameter);
        int rightH = heightTree(root->right,diameter);
        
        diameter = max(diameter, leftH + rightH);
        return 1 + max(leftH,rightH);
    }
};