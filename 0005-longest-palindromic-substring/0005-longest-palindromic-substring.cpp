#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";
        
        int start = 0, max_len = 0;

        // Lambda function to expand outward from the center
        auto expandFromCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            // Return the length of the palindrome found
            return right - left - 1;
        };

        for (int i = 0; i < s.length(); i++) {
            int len1 = expandFromCenter(i, i);
            
            int len2 = expandFromCenter(i, i + 1);
            
            int current_len = std::max(len1, len2);
            
            if (current_len > max_len) {
                max_len = current_len;
                start = i - (current_len - 1) / 2;
            }
        }

        return s.substr(start, max_len);
    }
};
