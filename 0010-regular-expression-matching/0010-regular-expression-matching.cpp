class Solution {
public:
    bool isMatch(string s, string p) {
        int n = size(s), m = size(p);
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        dp[n][m] = 1;
        
        for(int i = n; i >= 0; --i){
            for(int j = m - 1; j >= 0; --j){
                if(p[j + 1] == '*'){
                    dp[i][j] = dp[i][j + 2] || 
                        ( i < n && ( p[j] == '.' || s[i] == p[j] ) && dp[i + 1][j] );
                } else {
                    dp[i][j] = 
                        ( i < n && ( p[j] == '.' || s[i] == p[j] ) && dp[i + 1][j + 1] );
                }
            }
        }
        
        return dp[0][0];
    }
};