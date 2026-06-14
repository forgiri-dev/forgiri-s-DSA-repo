#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> res;
        std::deque<int> q;
        
        for(int i = 0; i < nums.size(); i++){
            
            if (!q.empty() && q.front() == i - k) {
                q.pop_front();
            }

            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }

            q.push_back(i);
            
            if (i >= k - 1) {
                res.push_back(nums[q.front()]);
            }
        }

        return res;
    }
};