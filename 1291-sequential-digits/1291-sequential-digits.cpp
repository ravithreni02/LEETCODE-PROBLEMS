class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string t="123456789";
        vector<int>res;
        for(int i=0;i<9;i++){
            for(int j=i;j<9;j++){
                string n=t.substr(i,j-i+1);
                int x=stoi(n);
                if(x>=low && x<=high)res.push_back(x);

            }
        }
        sort(res.begin(),res.end());
        return res;
        
    }
};