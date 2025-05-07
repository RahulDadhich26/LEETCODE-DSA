class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // sort(stations.begin(),stations.end());
        int count =0;
        priority_queue<int> maxHeap;
        int maxStepweCanGO = startFuel;
        int index = 0;
        while(maxStepweCanGO < target){
            
            while(index < stations.size() && stations[index][0] <= maxStepweCanGO){
                maxHeap.push(stations[index][1]);
                index++;
            }
            if(maxHeap.size() == 0) return -1;
            maxStepweCanGO += maxHeap.top();
            maxHeap.pop();
            count++;
        }
        return count;
    }
};