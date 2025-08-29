class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>res;
        for(int x : nums){
            if(x!=0){
                res.push_back(x);
            }
        }
        while(res.size() < nums.size()){
            res.push_back(0);
        }
        for(int i = 0 ; i < res.size();i++){
            nums[i] = res[i];
        }
    }
};