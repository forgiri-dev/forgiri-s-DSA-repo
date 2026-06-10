#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int total_water = 0;
        std::stack<int> st; 
        for (int i = 0; i < height.size(); i++) {
            
            while (!st.empty() && height[i] > height[st.top()]) {
                
                int valley_index = st.top();
                st.pop();
                
                if (st.empty()) {
                    break;
                }
                
                int left_index = st.top();
                
                int width = i - left_index - 1;
                int bounded_height = std::min(height[left_index], height[i]) - height[valley_index];
                
                total_water += width * bounded_height;
            }
            
            st.push(i);
        }
        
        return total_water;
    }
};