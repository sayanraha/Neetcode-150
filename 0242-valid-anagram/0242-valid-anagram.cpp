class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // Brute force solution
        // if(s.length() != t.length())return false;

        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());

        // return s == t ? true : false;


        // using hashmap

        if(s.length() != t.length())return false;

        unordered_map<int,int> m1;
        unordered_map<int,int> m2;

        for(int i = 0;i < s.length();i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }
        return m1 == m2;

    }
};