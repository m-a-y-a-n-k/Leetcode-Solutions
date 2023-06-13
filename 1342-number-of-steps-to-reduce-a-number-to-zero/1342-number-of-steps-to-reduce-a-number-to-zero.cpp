class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        while(num > 0){
            ++steps;
            if((num&1) == 0){
                num >>= 1;
            } else {
                --num;
            }
        }
        return steps;
    }
};