
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        vector<int> h(matrix[0].size() + 1, 0); 
        int area = 0; 

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '1'){
                    h[j] += 1;
                } else {
                    h[j] = 0;
                }
            }

            stack<int> st; 
            for(int k = 0; k < h.size(); k++){
                while(!st.empty() && h[st.top()] > h[k]){
                    int h1 = h[st.top()]; 
                    st.pop();
                    
                    int width; 
                    if(st.empty()){
                        width = k;
                    } else {
                        width = k - st.top() - 1;
                    }
                    
                    area = max(area, h1 * width); 
                }
                st.push(k); 
            }
        }
        
        return area; 
    }
};