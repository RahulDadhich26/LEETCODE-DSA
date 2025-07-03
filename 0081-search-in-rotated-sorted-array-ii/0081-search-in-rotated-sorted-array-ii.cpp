class Solution {
public:
    bool search(vector<int>& arr, int target) {
         if(arr.empty()) return false;
    
    int left = 0, right = arr.size() - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(arr[mid] == target) {
            return true;
        }
        
        // Handle duplicates - Critical edge case
        if(arr[left] == arr[mid] && arr[mid] == arr[right]) {
            left++;
            right--;
            continue;
        }
        
        // Check for overflow in mid calculation (already handled above)
        
        if(arr[left] <= arr[mid]) {
            if(target >= arr[left] && target < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if(target > arr[mid] && target <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return false;
    }
};