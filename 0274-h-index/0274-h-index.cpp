class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        vector<int>freq(n+1,0);
        
        for(auto ci : c){
            if(ci >= n){
                freq[n]++;
            }
            else{
                freq[ci]++;
            }
        }

       int total = 0;
       for(int h = n ; h >= 0 ; h--){
           total += freq[h];
           if(total >= h) return h;
       }
       return 0;
    }
};