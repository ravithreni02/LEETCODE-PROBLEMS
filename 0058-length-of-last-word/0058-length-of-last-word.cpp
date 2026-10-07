class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size() - 1;
        int count = 0;

        // Skip any trailing spaces at the end of the string
        while (len >= 0 && s[len] == ' ') {
            len--;
        }

        // Count characters of the last word
        while (len >= 0 && s[len] != ' ') {
            count++;
            len--;
        }

        return count;
    }
};
