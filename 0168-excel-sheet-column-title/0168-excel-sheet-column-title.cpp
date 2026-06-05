class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        
        if (n <= 26) {
            return string(1, char(64 + n));
        }
        
        int c = 0;
        
        while (n > 26) {
            n -= 26;
            c++;
        }
        
        return convertToTitle(c) + char(64 + n);
    }
};