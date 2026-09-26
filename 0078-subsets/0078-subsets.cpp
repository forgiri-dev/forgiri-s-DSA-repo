
class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        int n = nums.size();
        int t = 1 << n;
        std::vector<std::vector<int>> p;

        for (int m = 0; m < t; m++) {
            std::vector<int> s;
            for (int i = 0; i < n; i++) {
                if (m & (1 << i)) {
                    s.push_back(nums[i]);
                }
            }
            p.push_back(s);
        }

        return p;
    }
};