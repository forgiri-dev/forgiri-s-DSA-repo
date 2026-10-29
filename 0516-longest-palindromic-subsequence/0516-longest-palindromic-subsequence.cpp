class Solution {

public:
    int dp(int i, int j, string& t1, string& t2, vector<vector<int>>& t){
        if(i == t1.size() || j == t2.size()){return 0;}
        if(t[i][j] != -1){return t[i][j];}
        if(t1[i] == t2[j]){
            int q = 1+ dp(i+1, j+1, t1, t2, t);
            t[i][j] = q;
            return q;
        }else{
            int w = max(dp(i+1, j, t1, t2, t), dp(i, j+1, t1, t2, t));
            t[i][j] = w;
            return w;
        }
    
    
    
    }
    
    int longestPalindromeSubseq(string s) {
     string s1 = s;
     reverse(s1.begin(), s1.end());
     int n = s.size();
     vector<vector<int>> t(n+1, vector<int>(n+1, -1));
        return dp(0, 0, s, s1, t);
    }
};