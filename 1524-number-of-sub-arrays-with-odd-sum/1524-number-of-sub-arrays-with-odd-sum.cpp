class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
      const int MOD=1000000007;
      int  even=1;
      int odd=0;
      int sum=0;
      int count=0;
      for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum%2==1){
            count=(count+even)%MOD;
            odd++;
        }else{
            count=(count+odd)%MOD;
            even++;
        }
      }
      return count;
    }
};