class Solution {
public:
    bool isPalindrome(int x) {
        // Special cases: negative numbers and numbers ending in 0 (except 0 itself)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = (reversedHalf * 10) + (x % 10);
            x /= 10;
        }

        // For even lengths: x == reversedHalf
        // For odd lengths: x == reversedHalf / 10 (discards the middle digit)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
