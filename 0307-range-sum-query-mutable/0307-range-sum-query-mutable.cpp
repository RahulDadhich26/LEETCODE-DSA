class NumArray {
public:
    vector<int>v; // vector to store input vector
    int sum ; // sum of all element of the vector
    NumArray(vector<int>& nums) {
        v = nums;
        sum  = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
    }
    void update(int index, int val) {
         sum = sum - v[index];
         v[index] = val;
         sum += val;       
    } 
    int sumRange(int left, int right) {
         int res=sum; 
        for(int i=0;i<left;i++){  
            res-=v[i];
        }
        for(int i=right+1;i<v.size();i++){
            res-=v[i];
        }
        return res;
    }
};
