
class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> next_greater;
        std::stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                next_greater[st.top()] = num;
                st.pop();      }
            st.push(num);
        }

        std::vector<int> res;
        for (int num : nums1) {
            if (next_greater.count(num)) {
                res.push_back(next_greater[num]);
            } else {
                res.push_back(-1);
            }
        }

        return res;
    }
};