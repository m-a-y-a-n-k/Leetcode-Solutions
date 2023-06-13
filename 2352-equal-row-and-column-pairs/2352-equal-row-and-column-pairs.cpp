class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
         map<string, int> R;
        for(auto row: grid){
            string key = "";
            for(auto val: row){
                string part = to_string(val) + ",";
                key += part;
            }
            R[key]++;
        }
        int pairs = 0;
        for(int j = 0; j < grid[0].size(); ++j){
            string key = "";
            for(int i = 0; i < grid.size(); ++i){
                key += to_string(grid[i][j]) + ",";            
            }
            if(R[key] > 0){
                pairs += R[key];
            }
        }
        return pairs;
    }
};