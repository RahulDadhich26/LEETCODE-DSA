class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
         unordered_set<int>st;

         for(int num : nums){
            if(num > 0) st.insert(num);
         }

         int smallest = 1;
         while(true){
            if(st.find(smallest) == st.end()){
                return smallest;
            }
            smallest++;
         }
    }
};