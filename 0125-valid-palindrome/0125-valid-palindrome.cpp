class Solution {
public:
    bool isPalindrome(string s) {
        string s2 = "";
        
        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])){ 
                s2 += tolower(s[i]); 
            }
        }
        
        string s3 = s2; 
        reverse(s3.begin(), s3.end()); 
        
        return s3 == s2;
    }
};