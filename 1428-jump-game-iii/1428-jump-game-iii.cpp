class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        queue<int>q;
        q.push(start);

        while(!q.empty()){
            int i = q.front(); q.pop();
            if(i < 0 || i >= n || arr[i] < 0) continue;
            
            if(arr[i] == 0) return true;
            q.push(i + arr[i]);
            q.push(i - arr[i]);

            arr[i] = -arr[i];
        }
        return false;
    }
};