class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        result = []
        carry = 0
        i, j = len(num1) - 1, len(num2) - 1

        while i >= 0 or j >= 0 or carry:
            x1 = int(num1[i]) if i >= 0 else 0
            x2 = int(num2[j]) if j >= 0 else 0

            # Calculate sum of current digits and carry
            total = x1 + x2 + carry
            carry = total // 10  # Update carry for next iteration
            result.append(total % 10)  # Append the last digit of total to result

            i -= 1
            j -= 1

        # Convert result list to a string and reverse it
        return ''.join(map(str, result[::-1]))