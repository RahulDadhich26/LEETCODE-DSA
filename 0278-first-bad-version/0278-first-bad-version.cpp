class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1, e = n;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (isBadVersion(mid)) {
                e = mid;   // yaha ya left me answer
            } else {
                s = mid + 1; // right me answer
            }
        }
        return s; // or return e, dono equal honge
    }
};