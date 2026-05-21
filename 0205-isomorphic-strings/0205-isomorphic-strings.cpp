class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char mapS[256] = {0}; 
        char mapT[256] = {0}; 
        
        for(int i = 0; i < s.size(); i++){
            char charS = s[i];
            char charT = t[i];
            
            if (mapS[charS] != 0 && mapS[charS] != charT) {
                return false;
            }
            
            if (mapT[charT] != 0 && mapT[charT] != charS) {
                return false;
            }
            
            mapS[charS] = charT;
            mapT[charT] = charS;
        }
        
        return true;
    }
};