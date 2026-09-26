class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.size();
        unordered_map<string,string>mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                string keys="";
                i++;
                while(i<n&&s[i]!=')'){
                    keys+=s[i];
                    i++;
                }
                if(mp.find(keys)!=mp.end()){
                    ans+=mp[keys];
                }
                else{
                    ans+='?';
                }
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
        
    }
};