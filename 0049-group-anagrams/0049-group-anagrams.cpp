class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        if(strs.size() == 0)return {};

        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;

        string s, t;

        for(string str : strs)
        {
            s = t = str;
            sort(t.begin(),t.end());
            mp[t].push_back(s);
        }
        for(auto it : mp){
            res.push_back(it.second);
        }
        return res;
    }
};