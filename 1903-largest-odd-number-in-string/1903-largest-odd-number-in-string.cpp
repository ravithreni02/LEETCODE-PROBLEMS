class Solution {
public:
    string largestOddNumber(string s) {
        // Scan the string from right to left
        for (int i = s.length() - 1; i >= 0; i--) {
            // Check if the current digit character is odd
            if ((s[i] - '0') % 2 != 0) {
                // Return the prefix from start up to index i
                return s.substr(0, i + 1);
            }
        }
        // Return an empty string if no odd digit exists
        return "";
    }
};
