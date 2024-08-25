import math 

class Solution:
    def arrangeCoins(self, n: int) -> int:
        # Calculate the maximum k using the quadratic formula
        k = (-1 + math.sqrt(1 + 8 * n)) / 2
        return int(k)