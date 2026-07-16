class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int n=s.size();
        int l=0,r=0,maxlen=0;
        while(r<n){
            if (hash.count(s[r]) != 0) {
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;               
                }
            }
            int len=r-l+1;
            maxlen=max(len,maxlen);
            hash[s[r]]=r;
            r++;

        }
        return maxlen;
       
    }
};