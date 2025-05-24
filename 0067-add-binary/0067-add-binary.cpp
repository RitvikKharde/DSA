//Brute Force-
// class Solution {
// public:
//     string addBinary(string a, string b) {
//         int m = a.size();
//         int n = b.size();

//         vector<int> digit1, digit2;

//         for (int i = 0; i < m; i++) {
//             digit1.push_back(a[i] - '0');
//         }
//         for (int i = 0; i < n; i++) {
//             digit2.push_back(b[i] - '0');
//         }

//         string result;
//         int carry = 0;

//         int i = m - 1;
//         int j = n - 1;

//         while (i >= 0 || j >= 0 || carry) {
//             int sum = carry;
//             if (i >= 0) {
//                 sum += digit1[i];
//                 i--;
//             }
//             if (j >= 0) {
//                 sum += digit2[j];
//                 j--;
//             }
//             carry = sum / 2;
//             result.push_back((sum % 2) + '0');
//         }

//         reverse(result.begin(), result.end());

//         return result;
//     }
// };



class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        int i = m - 1;
        int j = n - 1;
        int carry = 0;
        string result;

        while (i >= 0 || j >= 0 || carry) {
            int digit1 = (i >= 0) ? a[i] - '0' : 0;
            int digit2 = (j >= 0) ? b[j] - '0' : 0;

            int sum = digit1 + digit2 + carry;
            carry = sum / 2;
            result.push_back((sum % 2) + '0');

            i--;
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
