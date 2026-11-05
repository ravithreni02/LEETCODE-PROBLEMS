class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans=0;
        for(int i=0;i<arr1.size();i++){
            bool ok =true;
            int x=arr1[i];
            int idx=lower_bound(arr2.begin(),arr2.end(),x)-arr2.begin();
            if(idx<arr2.size()){
                if(arr2[idx]<=x+d){
                    ok=false;
                }
            }
            if(idx>0){
                if(arr2[idx-1]>=x-d){
                    ok=false;
                }
            }
            if(ok){
                ans++;
            }
        }
        return ans;
    }
};