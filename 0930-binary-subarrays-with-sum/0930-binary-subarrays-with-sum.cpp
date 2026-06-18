class Solution {
private:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0; 
        
        int l = 0;
        int r = 0;
        int current_sum = 0;
        int count = 0;
        
        while (r < nums.size()) {
            current_sum += nums[r];
            
            while (current_sum > goal) {
                current_sum -= nums[l];
                l++;
            }
            
            count += (r - l + 1);
            r++;
        }
        
        return count;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};