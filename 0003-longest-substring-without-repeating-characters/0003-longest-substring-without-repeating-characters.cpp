class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() <= 1){
            return s.size();
        }
        
        unordered_set<char> charset;
        int i = 0;  
        int j = 0;  
        int mc = 0; 
        
        while(j < s.size()){
            
            if(charset.count(s[j]) == 0){
                charset.insert(s[j]);
                
                mc = max(mc, j - i + 1); 
                j++;
            }
            else {
                charset.erase(s[i]);
                i++;
            }
        }
        
        return mc;
    }
};