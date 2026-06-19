#include <vector>

using namespace std;

class Solution {
private:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0; 
        
        int l = 0;
        int r = 0;
        int odd_count = 0;
        int total_subarrays = 0;
        
        while (r < nums.size()) {
            if (nums[r] % 2 != 0) {
                odd_count++;
            }
            
            while (odd_count > k) {
                if (nums[l] % 2 != 0) {
                    odd_count--;
                }
                l++;
            }
            
            total_subarrays += (r - l + 1);
            r++;
        }
        
        return total_subarrays;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};