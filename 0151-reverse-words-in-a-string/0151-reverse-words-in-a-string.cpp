class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        string s2 = "";
        string curr = "";
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                curr += s[i];
            } else if (curr.length() > 0) {
                reverse(curr.begin(), curr.end());
                
                if (!s2.empty()) {
                    s2 += " "; 
                }
                s2 += curr;
                curr = ""; 
        }}
        
        if (curr.length() > 0) {
            reverse(curr.begin(), curr.end());
            if (!s2.empty()) {
                s2 += " ";
            }
            s2 += curr;
        }
        
        return s2;
    }
};