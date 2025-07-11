class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& current, int k,int target ,int start) {
            if (current.size() == k && target == 0) {
                result.push_back(current);
                return;
            } 
            if (current.size() == k || target < 0) return; 

            for (int i = start; i <= 9; i++) {
                current.push_back(i);      
                backtrack(result, current,k, target - i, i+1);  
                current.pop_back(); 
            }
        }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result, current,k , n, 1);
        return result;
    }
};