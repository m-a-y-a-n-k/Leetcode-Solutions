class Solution {
    int dir[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
        
    void dfs(vector<vector<char>>& G, vector<vector<bool>>& v, int i, int j, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m || v[i][j] || G[i][j] != '1'){
            return ;
        }
        
        v[i][j] = true;
        for(int k = 0; k < 4; k++){
            int x = i + dir[k][0], y = j + dir[k][1];
            dfs(G,v,x,y,n,m);
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    dfs(grid,vis,i,j,n,m);
                }
            }
        }
        return cnt;
    }
};