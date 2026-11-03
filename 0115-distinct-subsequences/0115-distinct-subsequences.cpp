class Solution {
public:
    int dp(int i, int j, string& s1, string& s2, vector<vector<int>>& t){
        if(j == s2.size()){return 1;}
        if(i == s1.size()){return 0;}
        if(t[i][j] != -1){
            return t[i][j];}else{


        if(s1[i] == s2[j]){
            return t[i][j] = dp(i+1, j, s1, s2, t) + dp(i+1, j+1, s1, s2, t);
        }else{
            return t[i][j] = dp(i+1, j, s1, s2, t);
        }
            }
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> table(s.size(), vector<int>(t.size()+1, -1));
        return dp(0, 0, s, t, table);

    }
};