class Solution {
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    bool safe(int r,int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m;
    }
    
    void fill(vector<vector<int>>& image, int r, int c, int n, int m, int s, int t, vector<vector<int>> &F){
        if(safe(r,c,n,m) && F[r][c] == -1 && image[r][c] == s){
            image[r][c] = t;
            F[r][c] = 1;
            for(int i = 0; i < 4; i++){
                int x = r + dir[i][0], y = c + dir[i][1];
                fill(image, x, y, n, m, s, t, F);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        int sColor = image[sr][sc];
        vector<vector<int>> F(n,vector<int>(m,-1));
        fill(image, sr, sc, n, m, sColor, color, F);
        return image;
    }
};