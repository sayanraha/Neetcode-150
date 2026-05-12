class Solution {
public:

    vector<vector<int>> dp;

    bool isSolve(vector<int>& nums, int s, int n)
    {
        if(s == 0)
        {
            return true;
        }

        if(n == 0)
        {
            return false;
        }

        if(dp[n][s] != -1)
        {
            return dp[n][s];
        }

        if(nums[n-1] <= s)
        {
            return dp[n][s] =
                isSolve(nums, s - nums[n-1], n-1) ||
                isSolve(nums, s, n-1);
        }

        return dp[n][s] = isSolve(nums, s, n-1);
    }

    bool canPartition(vector<int>& nums)
    {
        int sum = 0;

        for(int val : nums)
        {
            sum += val;
        }

        if(sum % 2 != 0)
        {
            return false;
        }

        int target = sum / 2;
        int n = nums.size();

        dp.assign(n + 1, vector<int>(target + 1, -1));

        return isSolve(nums, target, n);
    }
};