class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp;
        int INF = INT_MAX - 1;
       // int mod = 1e9 + 7;
        dp.assign(n + 1, vector<int>(amount+1,0));

        // Initialization (BC)
        for(int i = 0;i < n + 1;i++)
        {
            dp[i][0] = 0;
        }
        for(int j = 0; j < amount + 1; j++){
            dp[0][j] = INF;
        }

        // Initialization for 2nd row when only 1 coin is present

        for(int j = 1; j < amount + 1;j++){

            if(j % coins[0] == 0)
            {
                dp[1][j] = j / coins[0];
            }
            else{
                dp[1][j] = INF;
            }
        }

        // Choice Diagram
        for(int i = 2;i < n+1;i++){
            for(int j = 0; j < amount + 1; j++){

                if(coins[i-1] <= j)
                {
                    dp[i][j] = min((1 + dp[i][j-coins[i-1]]), dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }

            }
        }
        return dp[n][amount] >= INF ? -1 : dp[n][amount];
    }
};