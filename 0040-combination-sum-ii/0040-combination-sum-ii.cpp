class Solution {
public:
    void CSum(vector<vector<int>>& result, vector<int>&current, vector<int>& candidates, int target, int index){
           if (target == 0) {
            result.push_back(current);
            return;
        }
        if(target < 0 )return;

        for(int i = index; i < candidates.size();i++){
            if (i > index && candidates[i] == candidates[i-1]) continue;
            current.push_back(candidates[i]);
            CSum(result, current, candidates, target - candidates[i], i+1);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
         vector<vector<int>>result;
         vector<int> current;
        CSum(result,current,candidates,target,0);
        return result;
    }
};