class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>>heap;
        for(const auto& point:points){
            int x = point[0];
            int y = point[1];

            int dis = x * x + y * y;
            if(heap.size() < k){
                heap.push({dis ,point});
            } 
            else {
                if(dis < heap.top().first){
                    heap.pop();
                    heap.push({dis,point});
                }
            }
        }
        vector<vector<int>>result;
        while(!heap.empty()){
            result.push_back(heap.top().second);
            heap.pop();
        }
        return result;
    }
};