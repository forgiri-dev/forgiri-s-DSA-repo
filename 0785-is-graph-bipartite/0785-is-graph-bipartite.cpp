class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<char> c(graph.size(), 'c'); 
        

        for(int i = 0; i < graph.size(); i++) {
            
            if(c[i] == 'c') { 
                queue<int> q;
                q.push(i);
                c[i] = 'a'; 
                
                while(!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    
                    for(int neighbor : graph[curr]) {
                        

                        if(c[neighbor] == 'c') {
                            c[neighbor] = (c[curr] == 'a') ? 'b' : 'a';
                            q.push(neighbor);
                        } 
                        
                        else if(c[neighbor] == c[curr]) {
                            return false; 
                        }
                    }
                }
            }
        }
        
        return true;
    }
};