class Solution {
public:
    int dp(int i, int j, string& s1, string& s2, vector<vector<int>>& t){
        if(i == s1.size() || j == s2.size()){return 0;}
        if(t[i][j] != -1){return t[i][j];}

        if(s1[i]==s2[j]){
            int q = 1 + dp(i+1, j+1, s1, s2, t);
            t[i][j] = q;
            return q;
        } else {
            int w = max(dp(i, j+1, s1, s2, t), dp(i+1, j, s1, s2, t));
            t[i][j] = w;
            return w;
        }
    }

    int minInsertions(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        int n = s.size();
        vector<vector<int>> t(n+1, vector<int>(n+1, -1));
        int r = n - dp(0, 0, s, s1, t);
        return r;
    }
};