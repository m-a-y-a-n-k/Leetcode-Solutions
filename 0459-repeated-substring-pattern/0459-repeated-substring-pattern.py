class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        # Step 1: Create the concatenated string
        doubled_s = s + s

        # Step 2: Remove the first and last character
        modified_doubled_s = doubled_s[1:-1]

        # Step 3: Check if the original string is a substring of the modified string
        return s in modified_doubled_s