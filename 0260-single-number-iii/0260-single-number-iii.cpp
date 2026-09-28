class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }

        unsigned int diff = xorSum & -xorSum;

        int a = 0;
        int b = 0;
        for (int num : nums) {
            if (num & diff) {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        return {a, b};
    }
};