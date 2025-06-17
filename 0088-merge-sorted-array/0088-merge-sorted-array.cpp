class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0,j = 0;
        for(int i = 0 ;i<m+n;i++){
            if(i > m-1){
                nums1[i] = nums2[j++];
            }
        }
        sort(nums1.begin(),nums1.end());
        
    }
};