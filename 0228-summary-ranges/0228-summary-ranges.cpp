class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        
        int p1 = 0; 
        int p2 = 0; 
        
        while (p2 < nums.size()) {
            while (p2 + 1 < nums.size() && (long long)nums[p2 + 1] - nums[p2] == 1) {
                p2++;
            }
            
            if (p1 == p2) {
                result.push_back(to_string(nums[p1]));
            } else {
                result.push_back(to_string(nums[p1]) + "->" + to_string(nums[p2]));
            }
            
            p2++;
            p1 = p2;
        }
        
        return result;
    }
};