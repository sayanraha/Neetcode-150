class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> mp;

        for (auto n : nums){
            mp[n]++;
        }
        for(auto it : mp){
            if(it.second > 1){
                return true;
                break;
            }
        }
        return false;
    }
};