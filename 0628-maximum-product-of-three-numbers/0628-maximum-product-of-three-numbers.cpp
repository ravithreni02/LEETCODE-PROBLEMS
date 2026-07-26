class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a=INT_MIN;
        int b=INT_MIN;
        int c=INT_MIN;
        int x=INT_MAX;
        int y=INT_MAX;
        for(int&num:nums){
            int oa=a,ob=b,ox=x;
            a=max(a,num);
            b=max(b,min(oa,num));
            c=max(c,min(ob,num));
            x=min(x,num);
            y=min(y,max(ox,num));

        }
        return max(a*b*c,a*x*y);
    }
};