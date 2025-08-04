class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        // Step 1: Count frequency of each character
        for(char ch : s) {
            freqMap[ch]++;
        }
        
        // Step 2: Max-Heap based on frequency
        priority_queue<pair<int, char>> maxHeap;
        for(auto &entry : freqMap) {
            maxHeap.push({entry.second, entry.first});
        }
        
        // Step 3: Build result string
        string result = "";
        while(!maxHeap.empty()) {
            auto [freq, ch] = maxHeap.top();
            maxHeap.pop();
            result.append(freq, ch);  // Append character freq times
        }
        
        return result;
    }
};