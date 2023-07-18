class Solution {

public:
    double myPow(double x, int n) {
        long long N = n > 0 ? 1LL * n : -1LL *n;
        double ans = 1.0;
        while(N > 0){
            if(N % 2 == 1){
                ans *= x;
                --N;
            } else {
                x *= x;
                N >>= 1;
            }
        }
        if(n < 0){
            return 1.0 / ans;
        }
        return ans;
    }
};