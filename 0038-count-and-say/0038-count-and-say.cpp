class Solution {
    string say(string s){
        int n = size(s), c = 1;
        vector<pair<char,int>> freq;
        for(int i = 0; i + 1 < n; ++i){
            if(s[i] != s[i + 1]){
                freq.push_back({s[i], c});
                c = 0;
            }
            c++;
        }
        freq.push_back({s[n - 1], c});
        n = size(freq);
        string ans = "";
        
        for(int i = 0; i < n; ++i){
            ans += to_string(freq[i].second);
            ans += freq[i].first;
        }
        return ans;
    }
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        return say(countAndSay(n-1));
    }
};