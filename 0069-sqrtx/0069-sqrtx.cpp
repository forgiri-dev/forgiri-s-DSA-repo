class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }        
        
        int l = 1;
        int h = x;
        
        while (l <= h) {
            int mid = l + (h - l) / 2;
            
            long long square = (long long)mid * mid; 
            
            if (square == x) {
                return mid;
            }
            if (square > x) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return h; 
    }
};