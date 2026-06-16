class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::stack<char> st;
        
        for (char digit : num) {
            while (k > 0 && !st.empty() && st.top() > digit) {
                st.pop();
                k--;
            }
            
            if (!st.empty() || digit != '0') {
                st.push(digit);
            }
        }
        
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        if (st.empty()) {
            return "0";
        }
        
        std::string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        std::reverse(res.begin(), res.end());
        
        return res;
    }
};