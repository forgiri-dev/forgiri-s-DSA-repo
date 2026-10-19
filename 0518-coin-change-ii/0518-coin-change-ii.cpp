class Solution {
public:
    int dp(int i, int a, vector<int>& c, vector<vector<int>>& t){
        if(a == 0){return 1;}
        if(i == c.size()){return 0;}
        
        if(t[i][a] != -1){
            return t[i][a];
        }
        
        int skip = dp(i+1, a, c, t);
        int inc = 0;
        if(c[i] <= a){
            inc = dp(i, a-c[i], c, t);
        }
        
        t[i][a] = skip + inc;
        return skip + inc;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<vector<int>> t(n+1, vector<int>(amount+1, -1));
        
        return dp(0, amount, coins, t);
    }
};