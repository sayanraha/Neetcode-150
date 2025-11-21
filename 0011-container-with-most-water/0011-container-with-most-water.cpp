class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0, right = height.size() - 1;
        int maxVal = 0;
        while(left < right){
            
            int area = min(height[left],height[right]) * (right - left);
            maxVal = max(maxVal,area);
            if(height[left] < height[right]){
                left++;
            }
            else {
                right--;
            }
        }
        return maxVal;
    }
};