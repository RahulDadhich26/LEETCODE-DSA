class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);

        // mujhe hr window ka character count krna h 
        // phir usko window size - frequent char <= k se check krna hai
        // agar essa nhi hai to me apne left ko l++ krna dunga or vice versa 
        int l = 0;
        int r = 0;

        int n = s.size();
        int maxCount = 0;
        int maxLength = 0; 

        for(r = 0 ; r < n ;r++){
            freq[s[r] - 'A']++; 
            maxCount = max(maxCount, freq[s[r] - 'A']);
            int window = r - l + 1;

            if(window - maxCount > k){
                freq[s[l] - 'A']--;
                l++;
            }

            maxLength = max(maxLength, r - l + 1 );
        }
        return maxLength;
    }
};