class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort(p.begin(),p.end());
        int l = 0 ;
        int r = p.size()-1;
        int count = 0;
        while(l <= r){
            if(p[l] + p[r] <= limit){
                count++;
                l++;
                r--;
            }
            else if(p[r] <= limit){
                count++;
                r--;
            }
        }
        return count;
    }
};