class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        mp[0]= 1;
        int count = 0;
        int sum = 0;

        for(int x : nums){
            sum = (sum + x % k + k) % k;
            count += mp[sum];
            mp[sum]++;
        }
        return count;
    }
};