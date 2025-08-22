class Solution {
public:
    int numberOfSubstrings(string s) {
        // Striver's Sliding Window Approach
        // Time Complexity: O(n), Space Complexity: O(1)
        
        int n = s.length();
        int count = 0;
        
        // Array to store the last seen index of characters 'a', 'b', 'c'
        // lastSeen[0] = last index of 'a'
        // lastSeen[1] = last index of 'b' 
        // lastSeen[2] = last index of 'c'
        vector<int> lastSeen(3, -1);
        
        // Iterate through each character in the string
        for (int i = 0; i < n; i++) {
            // Update the last seen index of current character
            lastSeen[s[i] - 'a'] = i;
            
            // Check if we have seen all three characters at least once
            // If any character hasn't been seen yet, its lastSeen value will be -1
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                // Find the minimum index among all three characters
                // This represents the leftmost position where we have all three chars
                int minIndex = min({lastSeen[0], lastSeen[1], lastSeen[2]});
                
                // All substrings ending at current position 'i' and starting from
                // any position from 0 to minIndex will contain all three characters
                // So we add (minIndex + 1) to our count
                count += (minIndex + 1);
            }
        }
        
        return count;
    }
};

/* 
STRIVER'S APPROACH EXPLANATION:

1. CORE INSIGHT: For any ending position i, we need to count how many 
   starting positions will give us a valid substring containing a, b, c.

2. KEY OBSERVATION: If we know the last occurrence of each character (a, b, c)
   up to position i, then any substring ending at i and starting at or before
   the minimum of these last occurrences will contain all three characters.

3. ALGORITHM:
   - Maintain lastSeen array to track last occurrence of 'a', 'b', 'c'
   - For each position i, update lastSeen for current character
   - If all three characters have been seen, find minimum last occurrence
   - Add (minimum_index + 1) to result (all valid starting positions)

4. EXAMPLE with s = "abcabc":
   i=0, s[0]='a': lastSeen=[0,-1,-1] -> not all seen
   i=1, s[1]='b': lastSeen=[0,1,-1] -> not all seen  
   i=2, s[2]='c': lastSeen=[0,1,2] -> min=0, count += 1
   i=3, s[3]='a': lastSeen=[3,1,2] -> min=1, count += 2
   i=4, s[4]='b': lastSeen=[3,4,2] -> min=2, count += 3
   i=5, s[5]='c': lastSeen=[3,4,5] -> min=3, count += 4
   Total = 1+2+3+4 = 10

5. TIME: O(n) - single pass, SPACE: O(1) - constant extra space
*/