class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res = 0;
        int lsum = 0 , rsum = 0, maxSum = 0;   // result

        for(int i = 0 ;i < k;i++){
           lsum += cardPoints[i];
        }

         maxSum = lsum ;
        int rIndex = cardPoints.size()-1;
        for(int i = k-1; i>=0 ;i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rIndex];
            rIndex--;
            maxSum = max(maxSum,lsum + rsum) ;
        }
        return maxSum ;
    }
};