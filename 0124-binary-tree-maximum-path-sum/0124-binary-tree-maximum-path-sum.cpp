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
    int maxPathCheck(TreeNode* root, int &maxi){
        if(root == NULL)return 0;

        int leftH = max(0, maxPathCheck(root->left,maxi));
        int rightH = max(0, maxPathCheck(root->right, maxi));

        maxi = max(maxi, leftH + rightH + root->val);
        return max(leftH,rightH) + root->val;
        }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathCheck(root, maxi);
        return maxi;
    }
};