class Solution {
  int numberOfPowerfulInt(int start, int finish, int limit, String suffix) {
    int countPowerfulUpTo(int num) {
      String numStr = num.toString();
      int prefixLength = numStr.length - suffix.length;

      if (prefixLength < 0) return 0;

      List<List<int>> dp = List.generate(prefixLength + 1, (_) => List.filled(2, 0));

      dp[prefixLength][0] = 1;
      String suffixFromNum = numStr.substring(prefixLength);
      dp[prefixLength][1] = int.parse(suffixFromNum) >= int.parse(suffix) ? 1 : 0;

      for (int i = prefixLength - 1; i >= 0; i--) {
        int digitFromNum = int.parse(numStr[i]);

        dp[i][0] = (limit + 1) * dp[i + 1][0];

        if (digitFromNum <= limit) {
          dp[i][1] = digitFromNum * dp[i + 1][0] + dp[i + 1][1];
        } else {
          dp[i][1] = (limit + 1) * dp[i + 1][0];
        }
      }

      return dp[0][1];
    }

    return countPowerfulUpTo(finish) - countPowerfulUpTo(start - 1);
  }
}