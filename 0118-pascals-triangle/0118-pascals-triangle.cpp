class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res; 
        
        res.push_back({1});
        if (numRows == 1) {
            return res;
        }
        
        res.push_back({1, 1});
        
        for (int i = 3; i <= numRows; i++) {
            vector<int> v(i, 0);
            v[0] = 1;
            v[v.size() - 1] = 1; 
            
            for (int j = 1; j < i - 1; j++) {
                v[j] = res[res.size() - 1][j - 1] + res[res.size() - 1][j];
            }
            
            res.push_back(v);
        }
        
        return res;
    }
};