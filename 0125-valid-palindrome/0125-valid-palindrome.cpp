class Solution {
public:
    bool isalphanumeric(char ch){
        return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9');
    }
    char tolowerchar(char ch){
        if(ch>='A'&&ch<='Z'){
            return char(ch+32);
        }
        return ch;
    }
    bool isPalindrome(string s) {
        string cleaned;
        for(char ch:s){
            if(isalphanumeric(ch)){
                cleaned+=tolowerchar(ch);
            }
        }
        string reversestring=cleaned;
        reverse(reversestring.begin(),reversestring.end());
        return cleaned==reversestring;
        
    }
};