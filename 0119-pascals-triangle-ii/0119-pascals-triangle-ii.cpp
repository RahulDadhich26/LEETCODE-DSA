class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>res;
        res.push_back(1);
        for(int i=1;i<=rowIndex;i++){
            for(int j=i-1;j>=1;j--){
                 res[j] = res[j] + res[j - 1];
            }
            res.push_back(1);
        }
        return res;
    }
};