class Solution {
public:
    int hIndex(vector<int>& citations) {
          sort(citations.rbegin(), citations.rend()); // descending sort
    int h = 0;
    for(int i = 0; i < citations.size(); i++) {
        if(citations[i] >= i + 1) {
            h = i + 1;
        } else {
            break; // no further h possible
        }
    }
    return h;
    }
};