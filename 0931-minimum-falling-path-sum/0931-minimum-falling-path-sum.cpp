class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1) return matrix[0][0];

        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        
        for (int s = 0; s < n; s++) {
            dp[0][s] = matrix[0][s];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    dp[i][j] = matrix[i][j] + std::min(dp[i-1][j], dp[i-1][j+1]);
                } else if (j == n - 1) {
                    dp[i][j] = matrix[i][j] + std::min(dp[i-1][j], dp[i-1][j-1]);
                } else {
                    int s = std::min({dp[i-1][j], dp[i-1][j+1], dp[i-1][j-1]});
                    dp[i][j] = matrix[i][j] + s; 
                }
            }
        }

        return *std::min_element(dp[n-1].begin(), dp[n-1].end());
    }
};