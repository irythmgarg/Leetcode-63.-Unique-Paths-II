class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& given) {
        int m = given.size();        // Number of rows
        int n = given[0].size();     // Number of columns

        // Initialize a DP table with -1 to indicate unprocessed cells
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // If the starting or ending cell is an obstacle, return 0 (no path)
        if (given[0][0] == 1 || given[m - 1][n - 1] == 1)
            return 0;

        // Initialize the first column
        for (int i = 0; i < m; i++) {
            if (given[i][0] == 1)
                break;  // Stop if obstacle found
            dp[i][0] = 1;
        }

        // Initialize the first row
        for (int i = 0; i < n; i++) {
            if (given[0][i] == 1)
                break;  // Stop if obstacle found
            dp[0][i] = 1;
        }

        // Fill the rest of the DP table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // Skip this cell if it's an obstacle
                if (given[i][j] == 1)
                    continue;

                int ans = 0;

                // If the cell above is valid, add its path count
                if (dp[i - 1][j] != -1)
                    ans += dp[i - 1][j];

                // If the cell to the left is valid, add its path count
                if (dp[i][j - 1] != -1)
                    ans += dp[i][j - 1];

                // Only set dp[i][j] if there's at least one valid path to it
                if (ans != 0)
                    dp[i][j] = ans;
            }
        }

        // If destination is still -1, return 0 (no path)
        if (dp[m - 1][n - 1] == -1)
            return 0;

        // Return the number of unique paths to the bottom-right cell
        return dp[m - 1][n - 1];
    }
};
