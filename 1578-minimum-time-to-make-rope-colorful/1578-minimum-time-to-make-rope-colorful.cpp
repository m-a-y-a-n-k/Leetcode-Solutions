class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = size(colors);
        stack<int> S;
        
        S.push(0);
        int minTime = 0;
        
        for(int i = 1; i < n; ++i){
            if(!S.empty() && colors[S.top()] == colors[i]){
                if(neededTime[i] <= neededTime[S.top()]){
                    minTime += neededTime[i];
                } else {
                    minTime += neededTime[S.top()];
                    S.pop();
                    S.push(i);
                }
            } else {
                S.push(i);
            }
        }
        
        return minTime;
    }
};