class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        if(nums.size() == 0)return {};

        vector<int> res;
        unordered_map<int,int> mp;

        for(auto it : nums){
            mp[it]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for(auto &it : mp){
            bucket[it.second].push_back(it.first);
        }

        for(int i = nums.size(); i >= 0 and res.size() < k;i--){
            for(auto n : bucket[i]){
                res.push_back(n);
                if(res.size() == k)break;
            }
        }
        return res;
    }
};