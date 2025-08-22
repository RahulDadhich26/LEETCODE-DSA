class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, maxPick = 0;
        unordered_map<int,int>mpp;
        int r = 0;
        while(r < fruits.size()){

            mpp[fruits[r]]++;

            while(mpp.size() > 2){
                //maxPick = max(maxPick, )
                mpp[fruits[l]]--;
              if (mpp[fruits[l]] == 0) {
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            maxPick = max(maxPick, r - l + 1);
            r++;
        }
        return maxPick;
    }
};