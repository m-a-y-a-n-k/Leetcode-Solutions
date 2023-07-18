class Solution {
    map<int,int> store;
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
        if(store[n]){
            return store[n];
        }
        return store[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};