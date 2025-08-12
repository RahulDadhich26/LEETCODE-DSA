class Solution { // 28 ms, faster than 83.06%
public:
  
int kthSmallest(vector<vector<int>> &matrix, int k) {
    vector<int> arr;
    for (auto &row : matrix) {
        for (auto &val : row) {
            arr.push_back(val);
        }
    }
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}
};
