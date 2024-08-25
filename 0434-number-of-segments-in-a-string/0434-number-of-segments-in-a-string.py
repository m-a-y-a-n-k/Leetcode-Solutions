class Solution:
    def countSegments(self, s: str) -> int:
        # Strip leading and trailing spaces and split by spaces
        segments = s.strip().split()
        # Return the number of segments
        return len(segments)