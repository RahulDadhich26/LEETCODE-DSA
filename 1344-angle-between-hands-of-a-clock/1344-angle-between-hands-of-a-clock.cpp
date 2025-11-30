class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle = minutes * 6.0;
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;
        
        double diff = fabs(hourAngle - minAngle);
        return min(diff, 360.0 - diff);
    }
};