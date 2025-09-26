class Solution {
public:
    int numDifferentIntegers(string word) {
        string result = "";
        for(char ch : word){
            if(isdigit(ch)) result += ch;   // digit h to number me jodega
            else result += " ";            // digit na ho to space
        }
        stringstream ss(result);
        string num;
        set<string> uniqueNums;

        while(ss >> num){
            // leading zeros handle karne ke liye
            int i = 0;
            while(i < num.size() && num[i] == '0') i++;
            string clean = num.substr(i);

            if(clean == "") clean = "0"; // agar number pura zero ho
            uniqueNums.insert(clean);
        }

        return uniqueNums.size();
    }
};