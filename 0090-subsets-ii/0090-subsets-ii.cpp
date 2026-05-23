#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void helper(const vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& results) {
        results.push_back(curr);

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            curr.push_back(nums[i]);
            
            helper(nums, i + 1, curr, results);
            
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> curr;
        
        sort(nums.begin(), nums.end());
        
        helper(nums, 0, curr, results);
        
        return results;
    }
};