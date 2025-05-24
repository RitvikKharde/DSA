class Solution {
public:
    string convertToTitle(int columnNumber) {
        map<char, int> letterMap;
        for (char ch = 'A'; ch <= 'Z'; ++ch) {
            letterMap[ch] = ch - 'A' + 1;
        }

        string finalLetter = "";

        if (columnNumber <= 26) {
            char letter = 'A' + (columnNumber - 1);
            finalLetter += letter;
        } else {
            while (columnNumber > 0) {
                columnNumber--; 
                int remainder = columnNumber % 26;
                char letter = 'A' + remainder;
                finalLetter = letter + finalLetter;  
                columnNumber /= 26;
            }
        }

        return finalLetter;
    }
};
