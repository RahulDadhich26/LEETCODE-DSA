class Solution {
public:

    void CSum(vector<vector<int>>& result, vector<int>&current, vector<int>& candidates, int target, int index){
           if (target == 0) {
            result.push_back(current);
            return;
        }
        if(target < 0 )return;

        for(int i = index; i < candidates.size();i++){
             current.push_back(candidates[i]);
            CSum(result, current, candidates, target - candidates[i], i);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
         vector<int> current;
        CSum(result,current,candidates,target,0);
        return result;
    }
};