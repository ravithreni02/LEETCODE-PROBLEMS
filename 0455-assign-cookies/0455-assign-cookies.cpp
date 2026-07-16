#include <vector>
#include <algorithm>
using namespace std;

// YOU MUST INCLUDE THIS CLASS WRAPPER:
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; 
        int j = 0; 

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                i++; 
            }
            j++; 
        }

        return i; 
    }
}; // Don't forget the semicolon here!
