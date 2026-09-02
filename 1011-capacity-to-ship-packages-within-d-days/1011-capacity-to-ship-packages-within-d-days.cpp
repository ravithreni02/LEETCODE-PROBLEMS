#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getDays(vector<int>& weights, int mid) {
        int days = 1;
        int load = 0;
        
        for(int i = 0; i < weights.size(); i++) {
            if(load + weights[i] > mid) {
                days = days + 1;
                load = weights[i]; // Fixed typo: weights instead of weight
            } else {
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // Fixed: max_element returns an iterator, need to dereference it with '*'
        int low = *max_element(weights.begin(), weights.end()); 
        
        // Fixed: accumulate is used for summing a vector in C++
        int high = accumulate(weights.begin(), weights.end(), 0); 
        
        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2; // Declared mid and prevented overflow
            
            int no_of_days = getDays(weights, mid); // Fixed typo: weights instead of weight
            
            if(no_of_days <= days) {
                ans = mid;       // Store the potential answer
                high = mid - 1;  // Try to find a smaller capacity
            } else {
                low = mid + 1;   // Fixed: Must be mid + 1 to avoid an infinite loop
            }
        }
        return ans;
    }
};
