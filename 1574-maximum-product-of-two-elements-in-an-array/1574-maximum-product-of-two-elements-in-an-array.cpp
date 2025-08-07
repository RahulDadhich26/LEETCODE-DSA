class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = 0;
        int secondLargest = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] > largest){
                secondLargest = largest;
                largest = nums[i];
            }
           else {
              secondLargest = max(secondLargest,nums[i]);
           }
        }
        return (largest - 1) * (secondLargest - 1);
    }
};