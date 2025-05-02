class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = INT_MAX;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int temp = 0;

            for (int& pile : piles) {
                temp += pile / mid + (pile % mid != 0);
            }

            if (temp <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }
};