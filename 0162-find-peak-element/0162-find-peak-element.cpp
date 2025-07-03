class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
    
    // Edge case: Single element
    if(n == 1) return 0;
    
    // Edge case: Check boundaries
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;
    
    int left = 1, right = n - 2;  // Skip boundaries
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        // Peak mil gaya!
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
            return mid;
        }
        
        // Increasing slope - right side me peak hoga
        if(arr[mid] > arr[mid-1]) {
            left = mid + 1;
        }
        // Decreasing slope - left side me peak hoga
        else {
            right = mid - 1;
        }
    }
    
    return -1; 
    }
};