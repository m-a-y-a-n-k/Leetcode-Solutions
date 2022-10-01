#define pi pair<int,int>

class Solution {
    const int MAX = 1e6 + 5;

    int dirs[8][2] = {
        {0,1},
        {0,-1},
        {-1,0},
        {-1,-1},
        {-1,1},
        {1,0},
        {1,1},
        {1,-1}
    };
        
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = size(grid), m = size(grid[0]);       
        if(grid[n-1][m-1] || grid[0][0]){
            return -1;
        }       
        queue<pi> Q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        Q.push({0,0});
        vis[0][0] = true;
        
        int dis = 0;
        
        while(!Q.empty()){
            int s = Q.size();
            ++dis;
            while(s--){
                auto C = Q.front();
                Q.pop();
                
                if(C.first == n-1 && C.second == m-1){
                    return dis;
                }
                
                for(const auto &dir: dirs){
                    int x = C.first + dir[0], y = C.second + dir[1];
                    if(
                        (x < 0 || y < 0 || x >= n || y >= m) || 
                        vis[x][y] || grid[x][y]
                    ){
                        continue;
                    }
                    vis[x][y] = true;
                    Q.push({x,y});
                }
            }
        }
        
        return -1;        
    }
};