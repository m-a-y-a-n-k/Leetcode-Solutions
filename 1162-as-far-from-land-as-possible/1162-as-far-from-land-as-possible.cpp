typedef pair<int,int> pi;

class Solution {
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    bool safe(const pi &K, int n, int m){
        return (K.first >= 0 && K.first < n && K.second >= 0 && K.second < m);
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int d = 0, md = -1;
        int n = size(grid), m = size(grid[0]);
        queue<pi> Q;
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < m; ++c){
                if(grid[r][c]){
                    Q.push({r, c});
                }
            }
        }                
        
        while(!Q.empty()){
            int s = Q.size();
            d++;
            
            for(int x = 0; x < s; ++x){
                pi P = Q.front();
                Q.pop();
                for(int k = 0; k < 4; ++k){
                    pi K = {P.first + dir[k][0], P.second + dir[k][1]};
                    if(
                        safe(K, n, m) && 
                        !grid[K.first][K.second] && 
                        dp[K.first][K.second] > d
                    ){
                        Q.push({K.first, K.second});
                        dp[K.first][K.second] = d;
                    }
                }
            }
        }
        
        for(int r = 0; r < n; ++r){
            for(int c = 0; c < m; ++c){
                if(!grid[r][c]){
                    md = max(md, dp[r][c]);
                }
            }
        }
        
        return md == INT_MAX ? -1 : md;
    }
};