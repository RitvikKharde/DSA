class Solution {
    public int numDistinct(String s, String t) {
        int m = s.length();
        int n = t.length();

        // dp[i][j] = number of ways to form first j chars of t 
        //            using first i chars of s
        int[][] dp = new int[m + 1][n + 1];

        // Base case: empty t can be formed in exactly 1 way (by deleting all chars)
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        // Fill the dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If current characters match
                if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    // Option 1: match them (dp[i-1][j-1])
                    // Option 2: skip current char in s (dp[i-1][j])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    // If they don't match, skip current char in s
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Final answer: ways to form all of t from all of s
        return dp[m][n];
    }
}
