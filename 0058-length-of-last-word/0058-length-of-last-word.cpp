class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        int curr_length = 0; 
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                curr_length++; 
            } else if (curr_length > 0) {
                result = curr_length; 
                curr_length = 0;     
            }
        }
        
        if (curr_length > 0) {
            result = curr_length;
        }
        
        return result;
    }
};