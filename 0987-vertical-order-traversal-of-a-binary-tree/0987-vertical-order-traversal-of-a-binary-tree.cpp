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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;
        // if(root == NULL)return ans;

        map<int,map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* curr = p.first; // Node
            int x = p.second.first;// vertices
            int y = p.second.second;// level

            nodes[x][y].insert(curr->val);

            if(curr->left){
                q.push({curr->left,{x-1,y+1}});
            }
            if(curr->right){
                q.push({ curr->right,{x+1, y+1}});
            }
        }

        for(auto v : nodes){
            vector<int> col;
            for(auto v1 : v.second){
                col.insert(col.end(), v1.second.begin(),v1.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};