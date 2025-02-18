class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (int i = 0; i < points.size(); i++) {
            int px = points[i][0], py = points[i][1];

            if (px == x || py == y) { // Check if the point is valid
                int distance = abs(px - x) + abs(py - y); // Manhattan distance
                minHeap.push({distance, i}); // Push (distance, index) into min-heap
            }
        }
        return minHeap.empty() ? -1 : minHeap.top().second;
    }
};