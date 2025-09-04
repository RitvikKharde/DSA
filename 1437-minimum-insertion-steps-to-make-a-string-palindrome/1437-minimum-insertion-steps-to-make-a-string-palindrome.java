class Solution {
    public int minInsertions(String s) {
        int n = s.length();
        int[] dp = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            int prev = 0;
            for (int j = i; j < n; j++) {
                int temp = dp[j];
                if (i == j) {
                    dp[j] = 1;
                } else if (s.charAt(i) == s.charAt(j)) {
                    dp[j] = 2 + prev;
                } else {
                    dp[j] = Math.max(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }
        return n - dp[n - 1];
    }
}