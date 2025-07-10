class Solution {
public:
    void backtrack(vector<vector<int>> &result, vector<int>&curr, int index, int n, int k){
        if(curr.size() == k){
            result.push_back(curr);
            return;
        }

      for (int i = index; i <= n; i++) {
            curr.push_back(i);           // Choose
            backtrack(result, curr, i + 1, n, k);  // Explore
            curr.pop_back();             // Unchoose (Backtrack)
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>result;
        vector<int>curr;
        backtrack(result,curr,1,n,k);
        return result;
    }

};