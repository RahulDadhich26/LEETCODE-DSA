class Solution {
public:
    string frequencySort(string s) {
          unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    
    // Step 2: Make pairs of (frequency, character)
    vector<pair<int, char>> pairs;
    for (auto& p : freq) {
        pairs.push_back({p.second, p.first});
    }
    
    // Step 3: Sort by frequency (descending)
    sort(pairs.begin(), pairs.end(), greater<pair<int, char>>());
    
    // Step 4: Build result
    string result = "";
    for (auto& p : pairs) {
        result += string(p.first, p.second);
    }
    
    return result;
    }
};