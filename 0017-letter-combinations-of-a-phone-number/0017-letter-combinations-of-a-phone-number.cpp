class Solution {
public:
    vector<string> phNumber = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    void solve(int idx, string &digits, string &currStr, vector<string> &ans)
    {
        // Base case
        if(currStr.size() == digits.size())
        {
            ans.push_back(currStr);
            return;
        }

        int digitIdx = digits[idx] - '0';
        string value = phNumber[digitIdx];
        for (char ch : value)
        {
            currStr.push_back(ch);
            solve(idx+1,digits,currStr,ans);
            currStr.pop_back(); //Backtracking step
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string currStr = "";
        if(digits.size() == 0) return ans;
        solve(0,digits,currStr,ans);
        return ans;
    }
};