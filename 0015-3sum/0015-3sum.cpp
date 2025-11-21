class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;

        int i,j,k;

        for(i = 0; i < nums.size();i++){

            if( i  > 0 && nums[i] == nums[i-1])continue;
            j = i + 1;
            k = nums.size()-1;
            while(j < k){
             int target = nums[i] + nums[j] + nums[k];

                if(target > 0){
                    k--;
                }
                else if(target < 0){
                    j++;
                }
                else{
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;

                    while(nums[j] == nums[j-1] && j < k){
                        j++;
                    }
                }
            }
        }
        return res;
    }
};