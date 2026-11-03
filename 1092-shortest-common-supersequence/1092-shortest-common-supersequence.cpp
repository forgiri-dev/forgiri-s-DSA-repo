class Solution {
public:
    int dp(int i, int j, string& s1, string& s2, vector<vector<int>>& t) {
        if(i == s1.size() || j == s2.size()) {
            return 0;
        }
        
        if(t[i][j] != -1) {
            return t[i][j];
        }
        
        if(s1[i] == s2[j]) {
            return t[i][j] = 1 + dp(i+1, j+1, s1, s2, t);
        } else {
            return t[i][j] = max(dp(i+1, j, s1, s2, t), dp(i, j+1, s1, s2, t));
        }
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        vector<vector<int>> t(n + 1, vector<int>(m + 1, -1));
        
        dp(0, 0, str1, str2, t);
        
        string ans = "";
        int i = 0, j = 0;
        
        while(i < n && j < m) {
            if(str1[i] == str2[j]) {
                ans += str1[i];
                i++;
                j++;
            } else {
                if(dp(i+1, j, str1, str2, t) >= dp(i, j+1, str1, str2, t)) {
                    ans += str1[i];
                    i++;
                } else {
                    ans += str2[j];
                    j++;
                }
            }
        }
        
        while(i < n) {
            ans += str1[i++];
        }
        
        while(j < m) {
            ans += str2[j++];
        }
        
        return ans;
    }
};