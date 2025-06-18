class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long fmax=LONG_MIN;
        long smax=LONG_MIN;
        long tmax=LONG_MIN;
        for(int i : nums){
            if(i == fmax || i == smax || i == tmax) continue;
            if(i > fmax){
                tmax = smax;
                smax = fmax;
                fmax = i;
            }
            else if(i > smax){
                tmax = smax;
                smax = i;
            }
            else if(i > tmax) tmax = i;
        }
         if(tmax == LONG_MIN) return fmax;
         return tmax;
    }
};