class Solution {
public:
    int beautySum(string s) {
         int n = s.length();
         int totalBeauty = 0;

         for(int i = 0 ; i<s.length();i++){
            vector<int>freq(26,0);

            for(int j = i ; j<n;j++){
                freq[s[j] - 'a']++;

                int maxFreq = 0, minFreq = INT_MAX;

                for(int k = 0; k < 26; k++){
                    if(freq[k] > 0){
                        maxFreq = max(maxFreq,freq[k]);
                        minFreq = min(minFreq,freq[k]);
                    }
                }

                totalBeauty += (maxFreq - minFreq);
            }
         }
         return totalBeauty;
    }
};