#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Initialize the result matrix with a large number (infinity)
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        // Step 1: Find all 0s, set their distance to 0, and push them to the queue
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // Direction vectors for moving up, down, left, and right
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Step 2: Perform Multi-Source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            // Check all 4 adjacent neighbors
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                // If the neighbor is within bounds and we found a shorter path to it
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (result[nr][nc] > result[r][c] + 1) {
                        result[nr][nc] = result[r][c] + 1;
                        q.push({nr, nc}); // Push the updated neighbor to continue BFS
                    }
                }
            }
        }
        
        return result;
    }
};