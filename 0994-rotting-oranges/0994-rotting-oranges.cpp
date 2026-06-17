class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh{};
        int rs = grid.size();
        int cs = grid[0].size();
        int minutes{};
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        for(int i{}; i < rs; i++){
            for(int j{}; j < cs; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        if(fresh == 0){
            return 0;
        }
        
        while(!q.empty() && fresh > 0){
            int s = q.size();
            
            for(int k{}; k < s; k++){
                auto [r, c] = q.front();
                q.pop();
                
                for(auto d: directions){
                    int nr = r + d.first;
                    int nc = c + d.second;
                    
                    if(nr >= 0 && nc >= 0 && nr < rs && nc < cs){
                        if(grid[nr][nc] == 1){
                            grid[nr][nc] = 2;
                            fresh--;
                            q.push({nr, nc}); 
                        }
                    }
                }
            }
            minutes++; 
        }

        if(fresh != 0){
            return -1;
        } 
        return minutes;   
    }
};