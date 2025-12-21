class Solution {
public:
    bool isPalin(string &s,int start,int end)
    {
        while(start < end)
        {
            if(s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(int index,string &s,vector<string> &op, vector<vector<string>> &res)
    {
        // Base condition
        if(index == s.length())
        {
            res.push_back(op);
            return;
        }
        //All possible conditions
        for(int i = index;i < s.length();i++){

            if(isPalin(s,index,i))
            {
                op.push_back(s.substr(index,i - index + 1));
                solve(i+1,s,op,res);
                op.pop_back();// Backtracking step
            }
        }
    }
    vector<vector<string>> partition(string s) {
       vector<vector<string>> res;
       vector<string> op;
       solve(0,s,op,res);
       return res; 
    }
};