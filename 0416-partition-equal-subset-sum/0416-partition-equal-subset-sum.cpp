class Solution {
    int memo[201][20001]; 

    bool solve(int i, int diff, const std::vector<int>& nums) {
        if (i == nums.size()) {
            return diff == 0;
        }

        if (memo[i][diff] != -1) {
            return memo[i][diff];
        }

        bool add1 = solve(i + 1, diff + nums[i], nums);

        bool add2 = solve(i + 1, std::abs(diff - nums[i]), nums);

        return memo[i][diff] = (add1 || add2);
    }

public:
    bool canPartition(std::vector<int>& nums) {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;

        std::memset(memo, -1, sizeof(memo));
        return solve(0, 0, nums);
    }
};