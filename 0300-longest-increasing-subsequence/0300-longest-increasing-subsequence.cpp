class Solution {
public:
    vector<vector<int>> dp;
    int isSolve(int idx, int prev, vector<int> &nums)
    {
        if(idx == nums.size())
        {
            return 0;
        }

        if(dp[idx][prev + 1] != -1)
        {
            return dp[idx][prev+1];
        }

        int nottake = isSolve(idx + 1, prev , nums);

        int take = 0;
        if(prev == -1 || nums[idx] > nums[prev])
        {
            take = 1 + isSolve(idx + 1, idx , nums);
        }
        return dp[idx][prev + 1] = max(take , nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n + 1 , vector<int> (n + 1 , -1));
        return isSolve(0,-1,nums);
    }
};