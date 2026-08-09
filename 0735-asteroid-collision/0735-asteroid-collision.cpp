class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> st; // Use vector directly as a stack
        
        for (int i = 0; i < arr.size(); i++) {
            // Positive asteroids moving right never cause immediate collisions
            if (arr[i] > 0) {
                st.push_back(arr[i]);
            } 
            // Negative asteroid moving left
            else {
                // Destroy smaller positive asteroids moving right
                while (!st.empty() && st.back() > 0 && st.back() < abs(arr[i])) {
                    st.pop_back();
                }
                
                // Case 1: Both asteroids are equal size, they destroy each other
                if (!st.empty() && st.back() == abs(arr[i])) {
                    st.pop_back();
                } 
                // Case 2: No collision partners left, or the top is also moving left
                else if (st.empty() || st.back() < 0) {
                    st.push_back(arr[i]);
                }
                // Case 3: (Implicit) st.back() > abs(arr[i]), current asteroid is destroyed
            }
        }
        return st;
    }
};
