class Solution {
public:
    string reverseParentheses(string s) {
        int  n=s.size();
        stack<int> openbracketsidx;
        vector<int> door(n);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                openbracketsidx.push(i);
            }else if(s[i]==')'){
                int j=openbracketsidx.top();
                openbracketsidx.pop();
                door[i]=j;
                door[j]=i;
            }
        }
        string result;
        int flag=1;
        for(int i=0;i<n;i+=flag){
            if(s[i]=='('||s[i]==')'){
                i=door[i];
                flag=-flag;
            }else{
                result.push_back(s[i]);
            }
        }
        return result;
        
    }
};