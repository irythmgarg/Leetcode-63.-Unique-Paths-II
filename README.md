# Leetcode-63.-Unique-Paths-II

# Unique Paths II

## Problem Statement

You are given an `m x n` grid, where each cell can either be **empty (0)** or an **obstacle (1)**. You need to find how many unique paths exist from the **top-left** cell (0, 0) to the **bottom-right** cell (m-1, n-1), where you can only move **right** or **down**. Paths that pass through obstacles are invalid.

### Example

**Input:**

```cpp
[[0,0,0],
 [0,1,0],
 [0,0,0]]
```

**Output:**

```
2
```

**Explanation:** There are two valid paths: Right -> Right -> Down -> Down and Down -> Down -> Right -> Right.

---

## Approach 1: Recursive Backtracking

```cpp
class Solution {
public:
    int recur(vector<vector<int>>& given, int i, int j) {
        if (i == given.size() - 1 && j == given[0].size() - 1)
            return 1;

        if (i >= given.size() || j >= given[0].size() || given[i][j] == 1)
            return 0;

        return recur(given, i, j + 1) + recur(given, i + 1, j);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& given) {
        if (given[given.size() - 1][given[0].size() - 1])
            return 0;
        return recur(given, 0, 0);
    }
};
```

### Time Complexity: O(2^(m+n))

### Space Complexity: O(m+n) (Recursive stack)

### Pros:

* Easy to implement.

### Cons:

* Exponential time complexity, not feasible for large grids.

---

## Approach 2: Dynamic Programming (Tabulation)

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& given) {
        int m = given.size();
        int n = given[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        if (given[0][0] == 1 || given[m - 1][n - 1] == 1)
            return 0;

        for (int i = 0; i < m; i++) {
            if (given[i][0] == 1) break;
            dp[i][0] = 1;
        }

        for (int i = 0; i < n; i++) {
            if (given[0][i] == 1) break;
            dp[0][i] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (given[i][j] == 1) continue;
                int ans = 0;
                if (dp[i - 1][j] != -1) ans += dp[i - 1][j];
                if (dp[i][j - 1] != -1) ans += dp[i][j - 1];
                if (ans != 0) dp[i][j] = ans;
            }
        }

        if (dp[m - 1][n - 1] == -1) return 0;
        return dp[m - 1][n - 1];
    }
};
```

### Time Complexity: O(m \* n)

### Space Complexity: O(m \* n)

### Pros:

* Efficient for large inputs.
* Avoids recomputation by storing results.

### Cons:

* Uses extra space for the DP table.

---

## Summary

| Approach      | Time Complexity | Space Complexity | Handles Large Grids? |
| ------------- | --------------- | ---------------- | -------------------- |
| Recursion     | O(2^(m+n))      | O(m+n)           | No                   |
| Dynamic Prog. | O(m \* n)       | O(m \* n)        | Yes                  |

---

### Author

**Ridham Garg**
B.Tech, Computer Engineering
Thapar University, Patiala
Roll No: 102203014

