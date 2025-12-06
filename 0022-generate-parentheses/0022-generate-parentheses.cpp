class Solution {
public:
    void solve(int open, int close, int n, string op, vector<string> &res)
    {
        if(open == n and close == n){
            res.push_back(op);
            return;
        }
        if(open < n) solve(open+1,close,n,op + "(",res);
        if(close < open) solve(open, close+1,n,op+")",res);
    }
    vector<string> generateParenthesis(int n) {
        string op = "";
        vector<string> res;

        solve(0,0,n,op,res);
        return res;
    }
};