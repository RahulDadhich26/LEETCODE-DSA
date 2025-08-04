class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int totalsum = arr.size() * (arr.size() + 1) / 2;
        int localsum = 0;
        for(int i = 0 ; i< arr.size() ;i++){
            localsum += arr[i];
        }
        int ans = totalsum - localsum;
        return ans;
    }
};