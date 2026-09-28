class Solution {
public:
    int hammingWeight(int n) {
        int count{};
        while(n>0){
            n = n&(n-1);
            count++;
        }
        return count;
        
    }
};