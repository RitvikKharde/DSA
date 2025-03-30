#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
       string filteredString;
        for (char c : s) {
            if (isalnum(c)) {  
                filteredString += tolower(c); 
            }
        }
        int n = filteredString.size();
        for (int i = 0; i < n / 2; i++) {
            if (filteredString[i] != filteredString[n - i - 1]) {
                return false;
            }
        }
        
        return true;
    }
};
