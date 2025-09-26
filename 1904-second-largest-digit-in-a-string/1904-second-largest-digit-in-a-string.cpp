class Solution {
public:
    int secondHighest(string s) {
        set<int>set;

        for(char ch : s){
            if(isdigit(ch)) {
                set.insert(ch - '0');
            }
        }

        if(set.size() < 2) return -1;
        
        auto it = set.rbegin();
        ++it;
        return *it;
    }
};