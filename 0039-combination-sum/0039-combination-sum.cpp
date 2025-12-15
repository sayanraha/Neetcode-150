class Solution {
public:
 vector<vector<int>> result;
    void solve(vector<int> &ip,vector<int> &op,int start , int target,vector<vector<int>> &result){

        // Base case
        if(target == 0){
            result.push_back(op);
            return;
        }
        if(target < 0 || start >= ip.size()){
            return;
        }

        op.push_back(ip[start]);
        solve(ip,op,start,target - ip[start],result);
        op.pop_back();
        solve(ip,op,start+1,target,result);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       
        vector<int> op;
        solve(candidates,op,0,target,result);
        return result;
    }
};