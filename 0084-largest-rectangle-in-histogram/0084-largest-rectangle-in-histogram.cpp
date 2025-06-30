#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    
vector<int> nearestSmallerToLeft(const vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n, -1); // Initialize with -1 (no smaller element to the left)
    stack<int> s;
    
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return left;
}

vector<int> nearestSmallerToRight(const vector<int>& heights) {
    int n = heights.size();
    vector<int> right(n, n); // Initialize with n (no smaller element to the right)
    stack<int> s;
    
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    return right;
}

int largestRectangleArea(vector<int>& heights) {
    if (heights.empty()) return 0;
    
    vector<int> left = nearestSmallerToLeft(heights);
    vector<int> right = nearestSmallerToRight(heights);
    
    int maxArea = 0;
    for (int i = 0; i < heights.size(); ++i) {
        int width = right[i] - left[i] - 1;
        maxArea = max(maxArea, heights[i] * width);
    }
    return maxArea;
    }
};