class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxDepth = 0;
        for(auto c : s){
            if(c == '('){
                count++;
                if(maxDepth < count) maxDepth = count;
            }
            else if(c == ')') count--;
        }
        return maxDepth;
    }
};