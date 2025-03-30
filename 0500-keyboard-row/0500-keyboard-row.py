class Solution:
    def findWords(self, words: List[str]) -> List[str]:
 
        rows = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]
        result = []

        for word in words:
            first_char = word[0].lower()
            target_row = next(row for row in rows if first_char in row)

            if all(char.lower() in target_row for char in word):
                result.append(word)

        return result
