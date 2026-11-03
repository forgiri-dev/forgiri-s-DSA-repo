class Solution {
public:
    int dp(int i, int j, string& s1, string& s2, vector<vector<int>>& t) {
        if (i == s1.size()) return s2.size() - j;
        if (j == s2.size()) return s1.size() - i;

        if (t[i][j] != -1) {
            return t[i][j];
        }

        if (s1[i] == s2[j]) {
            return t[i][j] = dp(i + 1, j + 1, s1, s2, t);
        } else {
            int ic = dp(i, j + 1, s1, s2, t);
            int dc = dp(i + 1, j, s1, s2, t);
            int rc = dp(i + 1, j + 1, s1, s2, t);
            return t[i][j] = 1 + min({ic, rc, dc});
        }
    }
    
    int minDistance(string word1, string word2) {
        int a = word1.size();
        int b = word2.size();

        vector<vector<int>> t(a + 1, vector<int>(b + 1, -1));
        
        if (a == 0) { return b; }
        if (b == 0) { return a; }
        
        return dp(0, 0, word1, word2, t);
    }
};