class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // int maxlen = 0; // max length
        // int left = 0; 
        // agr no of zero aaye to me k-- krunga or dekhunga ki meri maximum len kya hai
        // sliding window se check krunga pr ensure krunga ki agr vo limit cross krega to left ko aage bada dunga 
        // for(int right = 0; right < nums.size() ; right++){
        //     if(nums[right] == 0){
        //         k--;
        //     }
        //     while(k < 0){  /// agr k minus me chala gya hai to hme left ko check krke aage bhadana pdega
        //         if(nums[left] == 0) k++;
        //         left++;
        //     }
          
        //   maxlen = max(maxlen, right - left + 1);
        // }
        // return maxlen;



        int l = 0, r = 0 , maxlen = 0;
        int zeros = 0;

        while(r < nums.size()){
            if(nums[r] == 0) zeros++;
            if(zeros > k){
                if(nums[l] == 0){
                    zeros--;
                }
               l++;
            }
            if(zeros <= k){
                int len = r-l+1;
                maxlen = max(maxlen,len);
            }
            r++;
        }
        return maxlen;
    }
};