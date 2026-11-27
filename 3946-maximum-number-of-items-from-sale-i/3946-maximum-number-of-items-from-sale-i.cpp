class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        int cheapest=items[0][1];
        vector<int> gain(n,0);
        for(int i=0;i<n;i++){
            cheapest=min(cheapest,items[i][1]);
            for(int j=0;j<n;j++){
                if(items[j][0]%items[i][0]==0){
                    gain[i]++;
                }
            }
        }
        vector<vector<int>>t(n+1,vector<int>(budget+1,0));
        for(int b=0;b<=budget;b++){
            t[0][b]=b/cheapest;
        }
        for(int i=1;i<=n;i++){
            int price=items[i-1][1];
            for(int b=0;b<=budget;b++){
                t[i][b]=t[i-1][b];
                if(price<=b){
                    t[i][b]=max(t[i][b],gain[i-1]+t[i-1][b-price]);
                }
            }
        }

        return t[n][budget];
    }
};