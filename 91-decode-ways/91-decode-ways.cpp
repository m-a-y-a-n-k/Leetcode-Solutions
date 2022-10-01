class Solution {
public:
    int numDecodings(string s) {
        int n = size(s);
        if(n == 0 || s[0] == '0'){
            return 0;
        }
        unordered_set<string> S;        
        for(int k = 1; k <= 26; ++k){
            S.insert(to_string(k));
        }
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        s = "$" + s;
        for(int i = 1; i <= n; ++i){
            auto s1 = s.substr(i, 1);
            auto s2 = s.substr(i-1, 2);
            
            if(S.find(s1) != S.end()){
                dp[i] += dp[i-1];
            }
            if(S.find(s2) != S.end()){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};