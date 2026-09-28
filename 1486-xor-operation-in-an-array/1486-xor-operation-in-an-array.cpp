class Solution {
public:
    int xorOperation(int n, int start) {
        int r{};
        for(int i{}; i < n; i++){
            int y = start + 2*i;
            r = r^y;
        }
        return r;
        
    }
};