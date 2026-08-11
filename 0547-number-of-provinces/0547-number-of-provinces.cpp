class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces++;
                
                stack<int> s;
                s.push(i);
                visited[i] = true; 
                
                while (!s.empty()) {
                    int node = s.top();
                    s.pop();
                    
                    for (int j = 0; j < n; j++) {
                        if (isConnected[node][j] == 1 && !visited[j]) {
                            visited[j] = true;
                            s.push(j);
                        }
                    }
                }
            }
        }

        return provinces;
    }
};