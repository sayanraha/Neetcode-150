class Solution {
public:
    int isSolve(vector<int> &nums, int n, vector<int> &dp)
    {
        if(n <= 0)return 0;
        if(n == 1)return nums[0];

        if(dp[n] != -1){
            return dp[n];
        }
        int pick = nums[n-1] + isSolve(nums,n - 2,dp);
        int notPick = isSolve(nums,n - 1,dp);

        dp[n] = max(pick,notPick);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1,-1);
        return isSolve(nums, n, dp );
    }
};