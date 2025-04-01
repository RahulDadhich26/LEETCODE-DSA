class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double>ans;
        double farenhiet = (celsius * 1.80) + 32.00;
        double kelvin = celsius + 273.15;
        ans.push_back(kelvin);
        ans.push_back(farenhiet);
        return ans;
    }
};