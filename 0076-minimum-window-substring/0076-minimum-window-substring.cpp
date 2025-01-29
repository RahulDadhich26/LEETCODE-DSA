class Solution {
public:
    string minWindow(string s, string p) {
        int len1 = s.length() ;
        int len2 = p.length() ;

        if(len1 < len2) return "";
        vector<int>hashP(256,0);
        vector<int>hashS(256,0);
        for(int i=0;i<len2;i++){
            hashP[p[i]]++;
        }
        int start = 0, start_idx = -1 , min_len = INT_MAX;
        int count = 0;
        for(int j = 0;j<len1;j++){
            hashS[s[j]]++;
            if(hashP[s[j]] != 0 && hashS[s[j]] <= hashP[s[j]]) count++;
            if(count == len2){
                while(hashS[s[start]] > hashP[s[start]] || hashP[s[start]] == 0){
                    if(hashS[s[start]] > hashP[s[start]]) hashS[s[start]]--;
                    start++;
                }
                int len = j - start + 1;
                if(min_len > len){
                    min_len = len ;
                    start_idx = start;
                }
            }
        }
        if(start_idx == -1) return "";
        return s.substr(start_idx , min_len);
    }
};