class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> result;
        string current = "";
        vector<string> phone = { "", "","abc","def",  "ghi",  "jkl",  "mno",  "pqrs","tuv","wxyz" 
        };
        backtrack(result, phone, digits, current, 0);
        return result;
    }
    
private:
    void backtrack(vector<string>& result, vector<string>& phone, 
                   string& digits, string& current, int index) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        int digit = digits[index] - '0';
        string letters = phone[digit];
        for (char letter : letters) {
            current.push_back(letter);   
            backtrack(result, phone, digits, current, index + 1);  
            current.pop_back(); 
        }
    }
};