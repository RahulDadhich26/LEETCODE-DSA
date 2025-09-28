class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string>word;

        istringstream iss(s);

        string w;

        while(iss >> w) word.push_back(w);

        if(pattern.size() != word.size()) return false;

        unordered_map<char, string>m1;

        unordered_map<string, char>m2;
        
        for(int i = 0 ; i < pattern.size() ; i++){

            char c1 = pattern[i]; 
            const string &c2 = word[i];
            
            if(m1.count(c1) && m1[c1] != c2) return false;
            if(m2.count(c2) && m2[c2] != c1) return false;

            m1[c1] = c2;
            m2[c2] = c1;
            
        }
        return true;
    }
};