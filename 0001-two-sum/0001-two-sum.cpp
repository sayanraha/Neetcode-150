class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        if(nums.size() == 0 )return {};

        vector<int> result;
        unordered_map<int,int> mp;
    
        for(int i = 0;i < nums.size();i++){
            int curr = target - nums[i];
            if(mp.find(curr)!= mp.end() and i!= mp[curr])
            {
                return {mp[curr],i};
            }
             mp[nums[i]] = i;
        }
        return result;

    }
};