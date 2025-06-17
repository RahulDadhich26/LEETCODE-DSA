class Solution {
public:
    int trap(vector<int>& height) {
        int left_max = 0;
        int right_max = 0;
        int water = 0;
        int l = 0;
        int r = height.size()-1;

        while(l <= r){
            left_max = max(left_max, height[l]);
            right_max = max(right_max, height[r]);

            if(left_max < right_max){
                water += left_max - height[l];
                l++;
            }
            else{
                 water += right_max - height[r]; 
                 r--;
            }
        }
        return water;
    }
};