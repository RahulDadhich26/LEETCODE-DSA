class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto num : nums){
            mpp[num]++;
        }
        auto comp = [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first > b.first;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)>heap(comp);
        for (const auto& entry : mpp) {
        int num = entry.first;
        int freq = entry.second;
        heap.push({freq, num});
        if (heap.size() > k) {
            heap.pop(); // Remove the smallest frequency element
        }
       }

       vector<int>topk;
       while(!heap.empty()){
        topk.push_back(heap.top().second);
        heap.pop();
       }
       return topk;
    }
};