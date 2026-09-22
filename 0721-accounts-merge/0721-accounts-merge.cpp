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

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> acc;
        unordered_map<string, string> emailToName;
        int c = 0;

        for (auto& a : accounts) {
            string name = a[0];
            for (int i = 1; i < a.size(); i++) {
                if (!acc.count(a[i])) {
                    acc[a[i]] = c++;
                }
                emailToName[a[i]] = name;
            }
        }

        parent.resize(c);
        rank.assign(c, 0);
        for (int j = 0; j < c; j++) {
            parent[j] = j;
        }

        for (auto& a1 : accounts) {
            int firstId = acc[a1[1]];
            for (int i = 2; i < a1.size(); i++) {
                uni(firstId, acc[a1[i]]);
            }
        }

        unordered_map<int, vector<string>> groups;
        for (auto& [email, id] : acc) {
            int root = find(id);
            groups[root].push_back(email);
        }

        vector<vector<string>> result;
        for (auto& [root, emailList] : groups) {
            sort(emailList.begin(), emailList.end());
            
            string name = emailToName[emailList[0]];
            emailList.insert(emailList.begin(), name);

            result.push_back(move(emailList));
        }

        return result;
    }
};