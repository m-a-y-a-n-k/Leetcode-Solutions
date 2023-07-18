class Solution {
    map<int, int> store;
public:
    int fib(int n) {
        if(n < 2){
            return n;
        }
        if(store[n]){
            return store[n];
        }
        return store[n] = fib(n-1) + fib(n-2);    
    }
};