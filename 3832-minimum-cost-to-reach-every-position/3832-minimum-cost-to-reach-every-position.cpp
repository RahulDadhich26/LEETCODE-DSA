class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
          int n = cost.size();
    vector<int> answer(n);
    int current_min = INT_MAX;
    for (int i = 0; i < n; ++i) {
        current_min = min(current_min, cost[i]);
        answer[i] = current_min;
    }
    return answer;
    }
};