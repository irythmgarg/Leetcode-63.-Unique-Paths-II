class Solution {
public:

    // Recursive function to count unique paths from cell (i, j) to the bottom-right corner
    int recur(vector<vector<int>>& given, int i, int j) {
        // Base case: if we reach the destination and it's not an obstacle, return 1 path
        if (i == given.size() - 1 && j == given[0].size() - 1)
            return 1;

        // Boundary or obstacle check: if out of bounds or on an obstacle, return 0 paths
        if (i >= given.size() || j >= given[0].size() || given[i][j] == 1)
            return 0;

        // Recursive call: move right (i, j+1) and down (i+1, j), sum their results
        return recur(given, i, j + 1) + recur(given, i + 1, j);
    }

    // Main function that starts the recursion
    int uniquePathsWithObstacles(vector<vector<int>>& given) {
        // Early exit: if the destination cell itself is an obstacle, no path exists
        if (given[given.size() - 1][given[0].size() - 1])
            return 0;

        // Start recursion from the top-left corner (0, 0)
        return recur(given, 0, 0);
    }
};
