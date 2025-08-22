class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int s=0,poddsum=0,count=0;
        vector<int>hash(nums.size()+1,0);
        hash[0]=1;
        while(s<nums.size())
        {
            if(nums[s]%2!=0)poddsum++;
            if(poddsum>=k)
            {
                count+=hash[poddsum-k];
            }
            hash[poddsum]++;
            s++;
        }
        return count;
    }
};