class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int result = 0;
        int count = 0;
        int i = 0;
        
        while (i < n) {
            if (s[i] == '(') {
                count++;
                i++;
            } else {
                if (count > 0) {
                    count--;
                } else {
                    result++; // Need a '(' to balance this ')'
                }
                
                if (i + 1 < n && s[i+1] == ')') {
                    i += 2; // Found consecutive '))'
                } else {
                    result++; // Need an extra ')' to complete the pair
                    i++;
                }
            }
        }
        
        // Add insertions needed for any remaining unmatched '('
        result += count * 2; 
        
        return result;
    }
};
