class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s;
        for(int i :nums){
            s.insert(i);
        }
        nums.clear();
        for(auto i:s){
            nums.push_back(i);
        }
        return nums.size();
    }
};