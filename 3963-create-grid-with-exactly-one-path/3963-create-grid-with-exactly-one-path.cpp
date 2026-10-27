class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string hash;
        string dot;
        for(int i=0;i<n;i++){
            if(i<n-1){
                hash+='#';
            }
            else{
                hash+='.';
            }
            dot+='.';
        }
        vector<string>answer;
        answer.push_back(dot);
        for(int i=0;i<m-1;++i){
            answer.push_back(hash);
        }
        return answer;

    }
};