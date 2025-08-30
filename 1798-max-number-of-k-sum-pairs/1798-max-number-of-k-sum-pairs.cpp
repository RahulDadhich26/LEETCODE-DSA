class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int count = 0;

        for(int num : nums){
           int need = k - num;
           
           if(mpp[need] > 0){
              count++;
              mpp[need]--;
           }
           else{
            mpp[num]++;
           }
        }
        return count;
    }
};