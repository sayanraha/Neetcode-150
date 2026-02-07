class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
            unordered_map<int,int> mp;
            mp[0] = 1; // base case v.v.vImp
            int sum = 0;
            int count = 0;
            for(int x : nums){
                sum = sum + x;

                if(mp.find(sum - k) != mp.end())
                {
                    count = count + mp[sum-k];
                }
                mp[sum]++;
            }
            return count;
    }
};