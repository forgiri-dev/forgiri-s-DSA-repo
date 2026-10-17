class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s{};
        int n = nums.size();
        for(int i{}; i < n; i ++){
            s += nums[i];
        }
        int p = (target + s)/2;
        if (abs(target) > s || (target + s) % 2 != 0) {
            return 0;
        }
        vector<int> t(p+1, 0);
        t[0] = 1;
        for(int i{}; i < n; i++){
            for(int j = p; j >=nums[i]; j--){
                t[j] += t[j-nums[i]];
            }
        }
        return t[p];

    }
};