class Solution {
public:
    int dp(int i, int j, string& s1, string& s2, vector<vector<int>>& t) {
        if (i == s1.size() || j == s2.size()) {
            return 0;
        }
        if (t[i][j] != -1) {
            return t[i][j];
        }

        if (s1[i] == s2[j]) {
            return t[i][j] = 1 + dp(i + 1, j + 1, s1, s2, t);
        } else {
            return t[i][j] = max(dp(i, j + 1, s1, s2, t), dp(i + 1, j, s1, s2, t));
        }
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> t(m + 1, vector<int>(n + 1, -1));
        
        int lcs = dp(0, 0, word1, word2, t);
        return (m - lcs) + (n - lcs); 
    }
};