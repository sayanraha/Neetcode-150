class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0)return 0;

        unordered_set<long long int> st;

        for(auto n : nums){
            st.insert(n); // will takes distinct values only
        }

        long long int lcs = 0;

        for(auto n : st){

            if(st.find(n-1) == st.end()){
                long long int currNum = n;
                long long int currSequence = 1;

                while(st.find(currNum+1) != st.end())
                {
                    currNum++;
                    currSequence++;
                }
                lcs = max(lcs,currSequence);
            }
        }
        return (int)lcs;
    }
};