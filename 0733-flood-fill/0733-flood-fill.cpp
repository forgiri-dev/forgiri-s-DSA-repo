class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        
        if (originalColor == color) {
            return image;
        }
        
        pair<int, int> directions[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        vector<vector<int>> result = image;
        
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        result[sr][sc] = color;
        
        int rows = image.size();
        int cols = image[0].size();
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            
            for (int i = 0; i < 4; i++) {
                int nr = r + directions[i].first;
                int nc = c + directions[i].second;
                
                
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && result[nr][nc] == originalColor) {
                    result[nr][nc] = color; 
                    q.push({nr, nc});       
                }
            }
        }
        
        return result;
    }
};