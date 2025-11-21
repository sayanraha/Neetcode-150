class Solution {
public:
    int trap(vector<int>& height) {
        
        int left = 0;
        int right = height.size() - 1;
        int leftMaxheight = 0, rightMaxheight = 0;
        int totalRain = 0;

        while(left  < right){

            if(height[left] <= height[right])
            {
                if(height[left] > leftMaxheight)
                {
                    leftMaxheight = height[left];
                }
                else
                {
                    totalRain += leftMaxheight - height[left];
                }
                left++;
            }
            else{

                if(height[right] > rightMaxheight){
                    rightMaxheight = height[right];
                }
                else{
                    totalRain += rightMaxheight - height[right];
                }
                right--;
            }
        }
        return totalRain;
    }
};