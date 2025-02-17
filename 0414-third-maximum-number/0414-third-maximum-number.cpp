class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int> , greater<int>>pq;
        unordered_set<int>distinctNums;

        for(auto num : nums){
            if(distinctNums.count(num)) continue;
            distinctNums.insert(num);

            if(pq.size() < 3){
                pq.push(num);
            }
            else if(num > pq.top()){
                pq.pop();
                pq.push(num);
            }
        }
        if(pq.size() == 3){
           return pq.top();
        }
        else{
            while(pq.size() > 1){
                 pq.pop();
            }
            return pq.top();
        }
    }
};