class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        # Edge case: More LEDs turned on than possible
        if turnedOn > 10:
            return []

        result = []

        # Check all possible hour and minute combinations
        for hour in range(12):
            for minute in range(60):
                # Count the number of 1's in the binary representation of hour and minute
                if bin(hour).count('1') + bin(minute).count('1') == turnedOn:
                    # Format the time correctly: hour:minute (minute should have two digits)
                    result.append(f"{hour}:{minute:02d}")

        return result
        
        