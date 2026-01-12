class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int mod = 1e9 + 7;
        int sumArr = 0;

        for(int s : nums){
            sumArr += s;
        }

        int sumS = (target + sumArr)/2;
        
        if((target + sumArr) % 2 != 0 || sumArr < abs(target))
        {
            return 0;
        }
        vector<vector<int>> dp;
        dp.assign(n + 1, vector<int> (sumS + 1, 0));

        //Initialize
        for(int i = 0;i < n + 1; i++)
        {
            dp[i][0] = 1;
        }

        //Choice diagram
        for(int i = 1;i < n + 1;i++)
        {
            for(int j = 0; j < sumS + 1; j++)
            {
                if(nums[i-1] <= j)
                {
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j-nums[i-1]]) % mod;
                }
                else
                {
                    dp[i][j] = dp[i-1][j] % mod;
                }
            }
        }
        return dp[n][sumS];
    }
};