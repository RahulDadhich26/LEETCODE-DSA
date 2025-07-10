class Solution {
public:
void solve(int i,int &n,vector<int> &v,vector<int> &t,vector<vector<int>> &ans){
    if(i>=n){
        ans.push_back(t);
        return;
    }
    solve(i+1,n,v,t,ans);
    t.push_back(v[i]);
    solve(i+1,n,v,t,ans);
    t.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> ans;
        int n = nums.size();
        solve(0,n,nums,tmp,ans);
        return ans;

    }
};