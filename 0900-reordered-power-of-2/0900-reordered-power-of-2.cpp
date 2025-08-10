class Solution {
public:
    // Helper: convert integer to its "digit signature" (sorted digits string)
    static string sig(int x) {
        string s = to_string(x);
        sort(s.begin(), s.end()); // O(D log D), D <= 10 for 1e9
        return s;
    }
    
    bool reorderedPowerOf2(int n) {
        // Build once: all power-of-two signatures up to 10^9 (2^0..2^30)
        static unordered_set<string> pow2Sigs = [](){
            unordered_set<string> st;
            for (int i = 0; i <= 30; ++i) {
                int val = 1 << i;        // 2^i
                st.insert(sig(val));     // store sorted digits
            }
            return st;
        }();
        
        // Check if n's digits can be reordered to any power of two
        // Leading zero is inherently handled since signatures must match exactly
        return pow2Sigs.count(sig(n)) > 0;
    }
};