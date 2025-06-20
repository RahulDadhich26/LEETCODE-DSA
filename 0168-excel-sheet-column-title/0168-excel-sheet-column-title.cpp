class Solution {
public:
    string convertToTitle(int columnNumber) {
          string result = "";
    
    while (columnNumber) {
        char ch = (65 + (columnNumber - 1) % 26);
        columnNumber = (columnNumber - 1)/26;
        result = ch + result;
    }
    return result;
    }
};