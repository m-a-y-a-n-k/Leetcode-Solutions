class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = size(matrix), n = size(matrix[0]);
        
        int r = m - 1, c = 0;
        
        while(1){
            int cr = r, cc = c;
            
            while(cr < m && cc < n){
                if(matrix[cr][cc] != matrix[r][c]){
                    return false;
                }
                ++cr;
                ++cc;
            }
            
            if(c == 0 && r > 0){
                --r;
            } else if(r == 0 && c < n){
                ++c;
            } 
            
            if(r == 0 && c == n){
                break;
            }
        }
        
        return true;
    }
};