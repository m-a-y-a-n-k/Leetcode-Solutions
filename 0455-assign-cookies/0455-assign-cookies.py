class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        # Sort the greed factors and cookie sizes
        g.sort()
        s.sort()

        i, j = 0, 0  # Initialize pointers for children and cookies
        while i < len(g) and j < len(s):
            if s[j] >= g[i]:  # If the current cookie can satisfy the current child
                i += 1  # Move to the next child
            j += 1  # Move to the next cookie

        return i  # The number of content children