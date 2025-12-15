class Solution {
public:

    void solve(vector<int> ip,vector<int> op,vector<vector<int>> &result){

        // Base condition
        if(ip.size() == 0){
            result.push_back(op);
            return;
        }

        vector<int> op1 = op; // exclued 
        vector<int> op2 = op; // include

        op2.push_back(ip[0]);
        ip.erase(ip.begin()+0); // making input smaller

        solve(ip,op1,result);
        solve(ip,op2,result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> op;
        solve(nums,op,res);
        return res;
    }
};