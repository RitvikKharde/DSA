class Solution {
    public boolean isMatch(String s, String p) {
        int m = s.length();
        int n = p.length();
        boolean[] dp = new boolean[n + 1];
        dp[0] = true;
        
        for (int j = 1; j <= n; j++) {
            if (p.charAt(j - 1) == '*') {
                dp[j] = dp[j - 1];
            } else {
                dp[j] = false;
            }
        }
        
        for (int i = 1; i <= m; i++) {
            boolean[] current = new boolean[n + 1];
            for (int j = 0; j <= n; j++) {
                if (j == 0) {
                    current[j] = false;
                } else {
                    char patternChar = p.charAt(j - 1);
                    char stringChar = s.charAt(i - 1);
                    if (patternChar == '?' || stringChar == patternChar) {
                        current[j] = dp[j - 1];
                    } else if (patternChar == '*') {
                        current[j] = current[j - 1] || dp[j];
                    } else {
                        current[j] = false;
                    }
                }
            }
            dp = current;
        }
        
        return dp[n];
    }
}