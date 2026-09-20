class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int total=0;
        for(int i=0;i<n;i++){
            int value='z'-s[i]+1;
            int position=i+1;
            total+=value*position;
        }
        return total;
    }
};