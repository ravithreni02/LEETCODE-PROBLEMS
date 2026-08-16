class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int v[3]{};
        for(auto &i:stones) v[i%3]++;
        if(v[0]%2==0)return v[1]&& v[2];
        return abs(v[2]-v[1])>2;
        
    }
};