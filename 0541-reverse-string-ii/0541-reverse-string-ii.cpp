class Solution {
public:
    string reverseStr(string s, int k) {
       int n = s.length();
        
        // Process string in chunks of 2k
        for (int i = 0; i < n; i += 2 * k) {
            // Find the end of current chunk (either 2k chars or end of string)
            int chunkEnd = min(i + 2 * k, n);
            
            // Find how many chars we have in this chunk
            int chunkSize = chunkEnd - i;
            
            // Reverse the first k characters of this chunk
            int reverseEnd = min(i + k, n);
            reverse(s.begin() + i, s.begin() + reverseEnd);
        }
        
        return s;
    }
};