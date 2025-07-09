class Solution {
public:
    vector<string> generateParenthesis(int n) {
         vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
private:
     void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // Base case: If we've used all n pairs of parentheses
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        // Decision 1: Add opening parenthesis
        // We can add '(' if we haven't used all n opening parentheses
        if (open < n) {
            backtrack(result, current + '(', open + 1, close, n);
        }
        
        // Decision 2: Add closing parenthesis
        // We can add ')' only if it won't make the string invalid
        if (close < open) {
            backtrack(result, current + ')', open, close + 1, n);
        }
    }
};