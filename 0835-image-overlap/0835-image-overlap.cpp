typedef pair<int,int> pi;

typedef map<pi, int> upi;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = size(img1);
        
        vector<pi> v1, v2;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(img1[i][j]){
                    v1.push_back({i,j});
                }
                if(img2[i][j]){
                    v2.push_back({i,j});
                }
            }
        }
        
        upi U;
        int ans = 0;
        
        for(auto &p1: v1){
            for(auto &p2: v2){
                int x = p1.first - p2.first;
                int y = p1.second - p2.second;
                U[{x,y}]++;
                ans = max(ans, U[{x,y}]);
            }
        }
        
        return ans;
    }
};