class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> result;
       vector<int>prevRow ;
       for(int i=0;i < numRows;i++){
           vector<int>Currentrow(i+1,1);
           for(int j=1;j < i;j++){
               Currentrow[j] = prevRow[j-1] + prevRow[j];
           }
           result.push_back(Currentrow);
           prevRow = Currentrow;
       }
       return result;
    }
};