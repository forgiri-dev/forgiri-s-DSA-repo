class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if (parent[i] == i) {
            return i;
        } else {
            return parent[i] = find(parent[i]);
        }
    }

    bool unin(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) {
            return false;
        }
        if (rank[rootx] > rank[rooty]) {
            parent[rooty] = rootx;
        } else if (rank[rootx] < rank[rooty]) {
            parent[rootx] = rooty;
        } else {
            parent[rootx] = rooty;
            rank[rooty]++;
        }
        return true;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        int comp = n;
        for (auto& edges : connections) {
            if (unin(edges[0], edges[1])) {
                comp--;
            }
        }

        return comp - 1;
    }
};