class Solution {
public:
    int maxVal(vector<int>& piles){
        int maxv = INT_MIN;
        for(int i = 0 ; i < piles.size() ;i++){
            maxv = max(maxv, piles[i]);
        }
        return maxv;
    }

    long long totalHours(vector<int>& piles, int hourly){
        long long th = 0;
        for(int i = 0 ; i < piles.size();i++){
            th += ceil((double)piles[i] / (double)hourly);
        }
        return th;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxVal(piles);
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long totalh = totalHours(piles,mid);
     
            if(totalh <= h){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};