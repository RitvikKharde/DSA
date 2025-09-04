
// class Solution {
//     public int longestValidParentheses(String s) {
//         int maxLen = 0;
//         Stack<Integer> stack = new Stack<>();
//         stack.push(-1); // Base for calculating length
        
//         for (int i = 0; i < s.length(); i++) {
//             char c = s.charAt(i);
//             if (c == '(') {
//                 stack.push(i);
//             } else {
//                 stack.pop();
//                 if (stack.isEmpty()) {
//                     stack.push(i);
//                 } else {
//                     maxLen = Math.max(maxLen, i - stack.peek());
//                 }
//             }
//         }
        
//         return maxLen;
//     }
// }





class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length();
        if (n <= 1) return 0;
        
        // dp[i] = length of longest valid parentheses substring ending at index i
        int[] dp = new int[n];
        int maxLen = 0;
        
        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == ')') {
                if (s.charAt(i - 1) == '(') {
                    // Case 1: ...()
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (dp[i - 1] > 0) {
                    // Case 2: ...))
                    // Find the matching '(' for current ')'
                    int matchIndex = i - dp[i - 1] - 1;
                    if (matchIndex >= 0 && s.charAt(matchIndex) == '(') {
                        dp[i] = dp[i - 1] + 2 + (matchIndex > 0 ? dp[matchIndex - 1] : 0);
                    }
                }
                maxLen = Math.max(maxLen, dp[i]);
            }
            // If s.charAt(i) == '(', dp[i] remains 0 (default)
        }
        
        return maxLen;
    }
}