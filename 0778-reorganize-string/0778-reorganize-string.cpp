class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char,int>mpp;
        for(int i = 0; i < s.size() ;i++){
            mpp[s[i]]++;
        }
        int max_freq = 0;
        char max_ch ;
        for(auto i : mpp){
            if(i.second > max_freq){
                max_freq = i.second;
                max_ch = i.first;
            }
        }
        int i = 0;
        while(i < n && max_freq){
            s[i] = max_ch;
            max_freq--;
            i+=2;
        }
        if(max_freq) return "";
        for(auto x : mpp){
            if(x.first == max_ch) continue;
            char ch = x.first;
            int freq = x.second;
           while(freq){
             if(i >= n){ i = 1;}
            s[i] = ch;
            freq--;
            i+=2;
           }
        }
        return s;
    }
};