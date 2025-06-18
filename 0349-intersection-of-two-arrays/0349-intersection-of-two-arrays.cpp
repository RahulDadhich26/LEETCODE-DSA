class Solution {
public:
    vector<int> intersection(vector<int>& n1, vector<int>& n2) {
        unordered_set<int>s;
        vector<int>ans;
        for(int i : n1){
            s.insert(i);
        }
        for(int i: n2){
            if(s.find(i) != s.end()){
                ans.push_back(i);
                s.erase(i);
            }
        } 
        return ans;
    }
};