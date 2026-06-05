class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int l = needle.size();
        
        if (h < l) {
            return -1;
        }

        for(int i = 0; i <= h - l; i++) {
            string s = haystack.substr(i, l);
            if(s == needle){
                return i;
            }
        }
        
        return -1;
    }
};