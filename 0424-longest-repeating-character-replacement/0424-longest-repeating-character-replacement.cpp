class Solution {
public:
    int characterReplacement(string s, int k) {
        
        if(s.empty())return 0;
        unordered_map<char,int> mp;

        int i = 0, j = 0, maxF = 0, ans = 0;
        while(j < s.length())
        {
            mp[s[j]]++;
            maxF = max(maxF,mp[s[j]]);

            while((j - i + 1) - maxF > k)
            {
                mp[s[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};