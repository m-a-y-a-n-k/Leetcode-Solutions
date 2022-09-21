class Solution {
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    
    void fill(vector<vector<int>>& image, int r, int c, int n, int m, int s, int t, vector<vector<int>> &F){
        if(r < 0 || c < 0 || r >= n || c >= m || image[r][c] != s || F[r][c] != -1){
            return ;
        }
        image[r][c] = t;
        F[r][c] = 1;
        for(int i = 0; i < 4; i++){
            int x = r + dir[i][0], y = c + dir[i][1];
            fill(image, x, y, n, m, s, t, F);
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