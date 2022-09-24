class Solution {
    vector<vector<bool>> atlantic, pacific;
    vector<vector<int>> ans;
    
    int dir[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};
        
    void dfs(
        vector<vector<int>>& heights, vector<vector<bool>> &visited, 
        int i, int j,
        int n, int m
    ){
        if(visited[i][j])
            return ;
        
        visited[i][j] = true;

        if(atlantic[i][j] && pacific[i][j]){
            ans.push_back({i,j});
        }

        for(int k = 0; k < 4; k++){
            int nx = i + dir[k][0], ny = j + dir[k][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]){
                continue;
            }
            if(heights[i][j] <= heights[nx][ny]){
                dfs(heights, visited, nx, ny, n, m);
            }
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n = size(heights);
        if(!n){
            return ans;
        }
        int m = size(heights[0]);
        
        pacific = atlantic = vector<vector<bool>>(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++){
            dfs(heights, pacific, i, 0, n, m);
            dfs(heights, atlantic, i, m - 1, n, m);
        }

        for(int i = 0; i < m; i++){
            dfs(heights, pacific, 0, i, n, m);
            dfs(heights, atlantic, n - 1, i, n, m);
        }
        
        return ans;
    }
};