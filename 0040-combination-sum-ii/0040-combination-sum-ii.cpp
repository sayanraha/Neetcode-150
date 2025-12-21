class Solution {
public:
    void solve(int index,vector<int> &candidates,int target,vector<int> &op,vector<vector<int>> &res)
    {
        // Base case
        if(target == 0)
        {
            res.push_back(op);
            return;
        }

        for(int i = index;i < candidates.size();i++)
        {
            if(i > index and candidates[i] == candidates[i-1])
            {
                continue;
            }
            if(candidates[i] > target)
            {
                break;
            }

            op.push_back(candidates[i]);
            solve(i+1,candidates,target - candidates[i],op,res);
            op.pop_back();//Backtracking step
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> op;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,op,res);
        return res;
    }
};