class Solution {
public:
    void solve(vector<int> &ip,int start,vector<vector<int>> &result)
    {
        // Base case
        if(start == ip.size()-1){
            result.push_back(ip);
            return;
        }

        for(int i = start;i < ip.size();i++)
        {
            swap(ip[i],ip[start]);
            solve(ip,start + 1,result);
            swap(ip[i],ip[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        solve(nums,0,res);
        return res;
    }
};