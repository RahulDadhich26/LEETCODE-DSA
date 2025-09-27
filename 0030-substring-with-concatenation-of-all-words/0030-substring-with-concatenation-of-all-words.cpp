class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.empty()) return ans;

        int wordSize = words[0].size();
        int wordCount = words.size();
        int N = s.size();

        unordered_map<string, int> originalCount;
        for (const string& word : words)
            originalCount[word]++;

        for (int offset = 0; offset < wordSize; offset++) {
            unordered_map<string, int> currentCount;
            int start = offset, count = 0;
            for (int end = offset; end + wordSize <= N; end += wordSize) {
                string currWord = s.substr(end, wordSize);
                if (originalCount.count(currWord)) {
                    currentCount[currWord]++;
                    count++;

                    while (currentCount[currWord] > originalCount[currWord]) {
                        string startWord = s.substr(start, wordSize);
                        currentCount[startWord]--;
                        start += wordSize;
                        count--;
                    }
                    if (count == wordCount)
                        ans.push_back(start);
                } else {
                    count = 0;
                    start = end + wordSize;
                    currentCount.clear();
                }
            }
        }
        return ans;
    }
};
