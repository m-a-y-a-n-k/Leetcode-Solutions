class Solution {
    
    vector<vector<int>> dp;
    vector<int> jobs;
    const int LIM = 1e9;
    
    int best(int i, int d, int n){
        if(d == 0){
            if(i == n){
                return 0;
            }
            return LIM;
        }
        if(i == n){
            return LIM;
        }
        if(dp[i][d] != -1){
            return dp[i][d];
        }
        int ans = LIM;
        int mx = jobs[i];
        
        for(int j = i; j < n; ++j){
            mx = max(mx, jobs[j]);
            ans = min(ans, best(j + 1, d - 1, n) + mx);
        }
        
        return dp[i][d] = ans;
    }
    
public:
    int minDifficulty(vector<int>& J, int d) {        
        jobs = J;
        int n = size(jobs);
        dp = vector<vector<int>>(n + 1, vector<int>(d + 1, -1));
        
        int minAns = best(0, d, n);
        
        if(minAns == LIM){
            return -1;
        }
        return minAns;
    }
};