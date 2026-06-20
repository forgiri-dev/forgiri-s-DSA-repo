class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int zero_count = 0;
        int max_len = 0;
        while (r < nums.size()) {
            if (nums[r] == 0) {
                zero_count++;
            }
            while (zero_count > k) {
                if (nums[l] == 0) {
                    zero_count--; 
                }
                l++;
            }
            max_len = max(max_len, r - l + 1);
            r++;
        }
        return max_len;
    }
};