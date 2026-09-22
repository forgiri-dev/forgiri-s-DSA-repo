class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool uni(int r, int c) {
        int rootr = find(r); 
        int rootc = find(c);

        if (rootr == rootc) {
            return false;
        }

        if (rank[rootr] > rank[rootc]) {
            parent[rootc] = rootr; 
        } else if (rank[rootr] < rank[rootc]) {
            parent[rootr] = rootc;
        } else {
            parent[rootr] = rootc;
            rank[rootc]++;
        }
        return true;
    }

    int removeStones(vector<vector<int>>& stones) {
        int maxr = 0;
        int maxc = 0;

        for (const auto& stone : stones) {
            maxr = max(maxr, stone[0]);
            maxc = max(maxc, stone[1]);
        }

    
        int totalNodes = maxr + 1 + maxc + 1;
        parent.resize(totalNodes);
        rank.assign(totalNodes, 0);

        for (int i = 0; i < totalNodes; i++) {
            parent[i] = i;
        }

    
        unordered_set<int> seenNodes;

        for (const auto& stone : stones) {
            int rowNode = stone[0];
            int colNode = stone[1] + maxr + 1;

            uni(rowNode, colNode);

            seenNodes.insert(rowNode);
            seenNodes.insert(colNode);
        }

        unordered_set<int> uniqueRoots;
        for (int node : seenNodes) {
            uniqueRoots.insert(find(node));
        }

        int components = uniqueRoots.size();
        return stones.size() - components;
    }
};