class Solution {
    static bool compare(const pair<int,int> &a,const pair<int,int> &b){
        return a.second > b.second;
    }
    
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        int n = size(p);
        
        vector<pair<int,int>> v(n);
        
        for(int i = 0; i < n; ++i){
            v[i] = {p[i], g[i]};
        }
        
        sort(begin(v), end(v), compare);
        
        int ct = 0, ans = 0;
        
        for(int i = 0; i < n; ++i){
            ct += v[i].first;
            ans = max(ans, ct + v[i].second);
        }
        
        return ans;
    }
};