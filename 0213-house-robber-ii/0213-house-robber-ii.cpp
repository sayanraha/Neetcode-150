class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if( n == 1)return nums[0];

        dp.assign(n+1,-1);
        int case1 = solve(nums, 0 , n-2);
        dp.assign(n+1,-1);
        int case2 = solve(nums, 1, n-1);
        return max(case1 , case2);
    }

    int solve(vector<int> &nums, int start ,int end){

        if(start > end)return 0;
        if(dp[start] != -1){
            return dp[start];
        }
        return dp[start] = max(nums[start] + solve(nums, start + 2, end) , solve(nums, start + 1, end));

    }

};