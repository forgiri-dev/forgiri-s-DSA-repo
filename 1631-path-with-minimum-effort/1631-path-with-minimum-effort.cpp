class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int effort = curr[0];
            int r = curr[1];
            int c = curr[2];
            
            if (r == m - 1 && c == n - 1) {
                return effort;
            }
            
            if (effort > dist[r][c]) continue;
            
            for (auto dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int jump = abs(heights[r][c] - heights[nr][nc]);
                    int new_effort = max(effort, jump);
                    
                    if (new_effort < dist[nr][nc]) {
                        dist[nr][nc] = new_effort;
                        pq.push({new_effort, nr, nc});
                    }
                }
            }
        }
        
        return 0;
    }
};