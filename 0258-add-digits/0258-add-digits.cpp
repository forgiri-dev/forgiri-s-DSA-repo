class Solution {
public:
    int addDigits(int num) {
        if (num == 0) {
            return 0;
        }        
        
        int x = num;
        
        while (x / 10 != 0) {
            int t = 0;
            
            while (x > 0) {
                t += x % 10;
                x = x / 10; 
            }
            
            x = t;            
        }

        return x;
    }
};