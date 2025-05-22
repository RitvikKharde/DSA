class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> alpha(52, 0);  // 26 for 'a'-'z', 26 for 'A'-'Z'
        int count = 0;
        int cc = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                alpha[s[i] - 'a']++;
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                alpha[26 + (s[i] - 'A')]++;
            }
            // Ignore any other characters (digits, symbols) for this logic
        }

        for (int i = 0; i < 52; i++) {
            if (alpha[i] % 2 == 0) {
                count += alpha[i];
            } else if (alpha[i] != 0) {
                cc = 1;
                if ((alpha[i] - 1) % 2 == 0) {
                    count += (alpha[i] - 1);
                }
            }
        }

        if (cc == 1) {
            count++;
        }

        return count;
    }
};
