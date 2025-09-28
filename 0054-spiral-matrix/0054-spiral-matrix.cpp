class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>result;
        int n = matrix.size();
        int m = matrix[0].size();
        
        int left = 0, right = m - 1, top = 0, bottom =  n - 1;

        while(left <= right && top <= bottom){

            for(int i = left; i <= right ; i++){
                result.push_back(matrix[top][i]);
            }
            top++;

            for(int i = top ;  i <= bottom ; i++){
                result.push_back(matrix[i][right]);
            }
            right--;

            if(top <= bottom){
                 for(int i = right; i >= left; i--){
                    result.push_back(matrix[bottom][i]);
                 }
                 bottom--;
            }
            if(left <= right){
                for(int i = bottom ; i >= top; i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
      return result;
    }
};