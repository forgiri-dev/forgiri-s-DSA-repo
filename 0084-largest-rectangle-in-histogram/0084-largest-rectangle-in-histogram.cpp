

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int max_area = 0;
        std::stack<int> st; 
        
        heights.push_back(0); 
        
        for (int i = 0; i < heights.size(); i++) {
            
            while (!st.empty() && heights[st.top()] > heights[i]) {
                
                int height = heights[st.top()];
                st.pop();
                
                int width;
                if (st.empty()) {
                    width = i; 
                } else {
                    int left_index = st.top();
                    width = i - left_index - 1;
                }
                
                max_area = std::max(max_area, height * width);
            }
            
            st.push(i);
        }
        
        return max_area;
    }
};