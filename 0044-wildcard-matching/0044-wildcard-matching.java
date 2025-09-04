class Solution {
    public boolean isMatch(String text, String pattern) {
        int textLength = text.length();
        int patternLength = pattern.length();
        
        // Create a DP table where dp[i][j] indicates if the first i characters of text
        // match the first j characters of pattern
        boolean[][] dp = new boolean[textLength + 1][patternLength + 1];
        
        // Empty text matches empty pattern
        dp[0][0] = true;
        
        // Handle patterns that start with '*' which can match empty text
        for (int patternIndex = 1; patternIndex <= patternLength; patternIndex++) {
            if (pattern.charAt(patternIndex - 1) == '*') {
                dp[0][patternIndex] = dp[0][patternIndex - 1];
            }
        }
        
        // Fill the DP table
        for (int textIndex = 1; textIndex <= textLength; textIndex++) {
            for (int patternIndex = 1; patternIndex <= patternLength; patternIndex++) {
                char currentPatternChar = pattern.charAt(patternIndex - 1);
                char currentTextChar = text.charAt(textIndex - 1);
                
                if (currentPatternChar == '?' || currentTextChar == currentPatternChar) {
                    // If characters match or pattern has '?', inherit from previous state
                    dp[textIndex][patternIndex] = dp[textIndex - 1][patternIndex - 1];
                } else if (currentPatternChar == '*') {
                    // '*' can match:
                    // 1. Zero characters: ignore '*' in pattern (dp[textIndex][patternIndex - 1])
                    // 2. One or more characters: use '*' to match current character (dp[textIndex - 1][patternIndex])
                    dp[textIndex][patternIndex] = dp[textIndex][patternIndex - 1] || dp[textIndex - 1][patternIndex];
                }
                // Else, characters don't match and pattern isn't special, so dp[textIndex][patternIndex] remains false
            }
        }
        
        return dp[textLength][patternLength];
    }
}