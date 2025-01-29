class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char ,int>seenIndex;
        int maxlength = 0;
        int left = 0;
        for(int right = 0 ; right < s.size() ;right++){
            char currentChar = s[right];
        
        if(seenIndex.find(currentChar)!=seenIndex.end() && seenIndex[currentChar] >= left){
              left = seenIndex[currentChar] + 1 ;
        }
        seenIndex[currentChar] = right;
        maxlength = max(maxlength , right - left + 1); 
        }
        return maxlength;
    }
};