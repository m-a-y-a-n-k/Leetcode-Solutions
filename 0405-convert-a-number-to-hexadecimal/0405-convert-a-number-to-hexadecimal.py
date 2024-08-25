class Solution:
    def toHex(self, num: int) -> str:
        # Handle zero case
        if num == 0:
            return "0"

        # Handle negative numbers using two's complement
        if num < 0:
            num += 2**32  # Add 2^32 to convert to positive equivalent in two's complement

        hex_chars = "0123456789abcdef"
        hex_str = ""

        while num > 0:
            hex_str = hex_chars[num % 16] + hex_str
            num //= 16

        return hex_str