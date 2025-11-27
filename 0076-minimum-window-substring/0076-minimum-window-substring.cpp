class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t.length() > s.length()) return "";

        unordered_map<char,int> mp;
        int i = 0,j = 0, minLen = INT_MAX,start = 0;
        int count = t.size();
        for(char ch : t){
            mp[ch]++;
        }
        while(j < s.size())
        {
            if(mp.find(s[j]) != mp.end())
            {
                if(mp[s[j]] > 0){
                    count--;
                }
                mp[s[j]]--;
            }
            while(count == 0)
            {
                if (j - i + 1 < minLen) {
                minLen = j - i + 1;
                start = i;
                }

                if(mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    if(mp[s[i]] > 0) count++;
                }
                i++;
            }
            j++;
        }
        return minLen == INT_MAX ? "" : s.substr(start,minLen);
    }
};