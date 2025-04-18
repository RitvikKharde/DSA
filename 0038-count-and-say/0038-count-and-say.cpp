class Solution {
public:
    string countAndSay(int n) {
    if (n == 1) return "1";

    string result = "1";

    for (int i = 2; i <= n; ++i) {
        string current = "";
        int len = result.length();

        for (int j = 0; j < len; ) {
            char ch = result[j];
            int count = 1;
 
            while (j + 1 < len && result[j] == result[j + 1]) {
                ++count;
                ++j;
            }
 
            current += to_string(count) + ch;
            ++j;
        }

        result = current;
    }

    return result;
}

};