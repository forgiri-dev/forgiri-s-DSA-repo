class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }

        std::string binary32 = std::bitset<32>(n).to_string();
        int c = 0;
        
        for(int i = 0; i < binary32.size(); i++){
            if(binary32[i] == '1'){
                c += 1;
            }
        }
        
        return c == 1;
    }
};