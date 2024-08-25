class Solution:
    def findComplement(self, num: int) -> int:
        # Step 1: Calculate the number of bits in the binary representation of num
        num_bits = num.bit_length()

        # Step 2: Create a mask with all bits set to 1
        # The mask has the same number of bits as num
        mask = (1 << num_bits) - 1

        # Step 3: Compute the complement
        return mask - num