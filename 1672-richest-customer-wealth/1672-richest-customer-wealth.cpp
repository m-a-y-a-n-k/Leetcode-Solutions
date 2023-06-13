class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = INT_MIN;
        for(auto account: accounts){
            int totalWealth = 0;
            for(auto wealth: account){
                totalWealth += wealth;
            }
            maxWealth = max(maxWealth, totalWealth);
        }
        return maxWealth;
    }
};