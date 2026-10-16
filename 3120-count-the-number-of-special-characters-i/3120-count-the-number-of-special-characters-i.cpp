class Solution {
public:
    int numberOfSpecialChars(string word) {
        // Track seen lowercase and uppercase characters using boolean arrays (hash maps)
        vector<bool> lower(26, false);
        vector<bool> upper(26, false);
        
        // Mark characters as seen
        for (char c : word) {
            if (c >= 'a' && c <= 'z') {
                lower[c - 'a'] = true;
            } else if (c >= 'A' && c <= 'Z') {
                upper[c - 'A'] = true;
            }
        }
        
        // Count how many letters appear in both casings
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (lower[i] && upper[i]) {
                count++;
            }
        }
        
        return count;
    }
};
