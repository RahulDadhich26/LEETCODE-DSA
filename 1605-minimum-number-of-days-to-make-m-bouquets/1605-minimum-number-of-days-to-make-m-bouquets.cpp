class Solution {
public:
     int possible(vector<int> & arr ,int day ,int m ,int k){
         int count =0;
           int noofb = 0; // no of boukets
        for(int i =0;i<arr.size();i++){
            if(arr[i]<= day){
                count++;
            }
            else{
                noofb += (count / k);
                count =0;
            }
        }
        noofb += (count / k);
        return noofb >= m;
     }
    int minDays(vector<int>& bloomDay, int m, int k) {
         long long var = m * 1ll * k * 1ll ;
         if( var > bloomDay.size()) return -1;
         int mini = INT_MAX , maxi = INT_MIN;
         for(int i=0;i<bloomDay.size() ;i++){
             mini = min(mini ,bloomDay[i]);
             maxi = max(maxi ,bloomDay[i]);

         }
         int low = mini ; int high = maxi ;
         while(low <= high){
             int mid = low + (high - low)/2;
             if(possible(bloomDay,mid,m,k)){
                 high = mid - 1;
             }
             else {
                 low = mid + 1;
             }

         }
       return low ;
    }
};