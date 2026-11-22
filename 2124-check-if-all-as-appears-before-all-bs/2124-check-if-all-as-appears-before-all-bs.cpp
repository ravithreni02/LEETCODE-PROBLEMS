class Solution {
public:
    bool checkString(string s) {
        bool b=false;
        for(auto u:s){
            if(u=='a'){
                if(b)return 0;
            }
            else{
                b=true;
            }
        }
        return 1;
    }
};