class Solution {
public:
    int countstudents(vector<int>&arr,int pages){
        int students=1;
        long long pagesstudent=0;
        for(int i=0;i<arr.size();i++){
            if(pagesstudent+arr[i]<=pages){
                pagesstudent+=arr[i];
            }
            else{
                students+=1;
                pagesstudent=arr[i];
            }
        }
        return students;
    }
    int findpages(vector<int>&arr,int n,int m){
        if(m>n)return-1;
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int students=countstudents(arr,mid);
            if(students>m){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
    int splitArray(vector<int>& a, int k) {
        return findpages(a,a.size(),k);
    }
};