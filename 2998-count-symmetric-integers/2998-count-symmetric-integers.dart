class Solution {
  int countSymmetricIntegers(int low, int high) {
    int count = 0;

    for (int num = low; num <= high; num++) {
      String strNum = num.toString();
      int len = strNum.length;

      // Consider only even-digit numbers
      if (len % 2 == 0) {
        int half = len ~/ 2;
        int sum1 = 0;
        int sum2 = 0;

        for (int i = 0; i < half; i++) {
          sum1 += int.parse(strNum[i]);
        }

        for (int i = half; i < len; i++) {
          sum2 += int.parse(strNum[i]);
        }

        if (sum1 == sum2) {
          count++;
        }
      }
    }

    return count;
  }
}
