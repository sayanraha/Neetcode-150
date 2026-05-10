class Solution {
public:

    vector<int> dp;

    bool isSolve(string &s, int idx, vector<string> &wordDict)
    {
        // Base case
        if(idx == s.size()){
            return true;
        }

        // Already computed
        if(dp[idx] != -1){
            return dp[idx];
        }

        for(string str : wordDict){

            int l = str.length();

            // Check boundary + prefix match
            if(idx + l <= s.size() && s.substr(idx, l) == str){

                // Try remaining string
                if(isSolve(s, idx + l, wordDict)){
                    return dp[idx] = true;
                }
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();

        dp.assign(n + 1, -1);

        return isSolve(s, 0, wordDict);
    }
};