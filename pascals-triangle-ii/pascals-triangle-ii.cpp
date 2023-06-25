class Solution {
    vector<vector<int>> rows;
    
    void generateTriangle(int rowIndex){
        if(rowIndex < 0){
            return ;
        }
        vector<int> row;
        if(rowIndex == 0){
            row.push_back(1);
            rows.push_back(row);
            return ;
        }
        if(rowIndex == 1){
            generateTriangle(0);
            row.push_back(1);
            row.push_back(1);
            rows.push_back(row);
            return ;
        }
        generateTriangle(rowIndex - 1);
        for(int i = 0; i <= rows[rowIndex - 1].size(); ++i){
            if(i == 0 || i == rows[rowIndex - 1].size()){
                row.push_back(1);
            } else {
                row.push_back(rows[rowIndex - 1][i - 1] + rows[rowIndex - 1][i]);
            }
        }
        rows.push_back(row);
    }
    
public:
    vector<int> getRow(int rowIndex) {
        
        generateTriangle(rowIndex);
        
        return rows[rowIndex];
    }
};