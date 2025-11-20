class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // if(nums.size() == 0)return {};
        // int n = nums.size();
        // vector<long> pref(n);
        // vector<long> suff(n);
        // vector<int> res(n);

        // pref[0] = 1;
        // suff[n-1] = 1;

        // // Prefix operation
        // for(int i = 1;i < n;i++){
        //     pref[i] = nums[i-1] * pref[i-1];
        // }

        // // Suffix operation
        // for(int i = n-2; i>=0;i--){
        //     suff[i] = suff[i+1] * nums[i+1];
        // }

        // // Product of Prefix and Suffix
        // for(int i = 0;i < n;i++){
        //     res[i] = pref[i] * suff[i];
        // }
        // return res;



        // Another optimal approach:

        if(nums.size()==0) return {};

        vector<int> res(nums.size(),1);

        for(int i = 1; i < nums.size();i++){
            res[i] = res[i-1] * nums[i-1];
        }
        int postFix = 1;

        for(int i = nums.size()-1;i >= 0;i--){
            res[i] *= postFix;
            postFix *= nums[i];
        }
        return res;
    }
};