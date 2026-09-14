class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Check if rec1 is to the left/right/below/above rec2 mutually
        return rec1[0] < rec2[2] && // rec1's left is-left-of rec2's right
               rec2[0] < rec1[2] && // rec2's left is-left-of rec1's right
               rec1[1] < rec2[3] && // rec1's bottom is-below rec2's top
               rec2[1] < rec1[3];   // rec2's bottom is-below rec1's top
    }
};
