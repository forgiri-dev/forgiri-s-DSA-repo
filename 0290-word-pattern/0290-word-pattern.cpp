

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        int n = s.length();
        int i = 0; 
        int p_idx = 0; 
        
        while (i < n) {
            if (p_idx == pattern.size()) {
                return false;
            }
            
            int j = i;
            while (j < n && s[j] != ' ') {
                j++;
            }
            
            string word = s.substr(i, j - i);
            char c = pattern[p_idx];
            
            if (charToWord.count(c) && charToWord[c] != word) {
                return false;
            }
            
            if (wordToChar.count(word) && wordToChar[word] != c) {
                return false;
            }
            
            charToWord[c] = word;
            wordToChar[word] = c;
            
            p_idx++;
            i = j + 1; 
        }
        
        return p_idx == pattern.size();
    }
};