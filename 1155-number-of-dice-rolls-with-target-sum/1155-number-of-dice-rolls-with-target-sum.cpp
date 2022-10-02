const int MOD = 1e9 + 7;

class Solution {
    vector<vector<int>> dp;
    
    int solve(int n, int k, int c){
        if(n < 0 || c < 0){
            return 0;
        }
        if(n == 0 && c == 0){
            return 1;
        }
        if(dp[c][n] != -1){
            return dp[c][n];
        }
        int ans = 0;
        for(int f = 1; f <= k; f++){
            ans = ( ans % MOD + solve(n - 1, k, c - f) % MOD ) % MOD;
        }
        dp[c][n] = (MOD + ans) % MOD;
        return dp[c][n];
    }
    
public:
    int numRollsToTarget(int n, int k, int target) {    
        
        dp = vector<vector<int>>(target + 1, vector<int>(n + 1, -1));
        
        return solve(n, k, target);
    }
};