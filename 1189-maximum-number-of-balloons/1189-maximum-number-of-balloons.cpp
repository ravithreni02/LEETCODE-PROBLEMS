class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;
        for(char ch:text){
            mp[ch]++;
        }
        mp['l']/=2;
        mp['o']/=2;
        return min({mp['b'],mp['a'],mp['l'],mp['o'],mp['n']});      
    }
};