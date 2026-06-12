
class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::vector<int> st;
        
        for (int ast : asteroids) {
            bool exploded = false;
            
            while (!st.empty() && ast < 0 && st.back() > 0) {
                
                if (st.back() < std::abs(ast)) {
                    st.pop_back();
                    continue; 
                } 
                else if (st.back() == std::abs(ast)) {
                    st.pop_back();
                }
                
                exploded = true;
                break;
            }
            
           
            if (!exploded) {
                st.push_back(ast);
            }
        }
        
        return st;
    }
};