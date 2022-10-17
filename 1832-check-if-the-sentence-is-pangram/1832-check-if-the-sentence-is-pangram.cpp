class Solution {
public:
    bool checkIfPangram(string s) {
        int n = size(s);
        vector<bool> mark(26, false);

        for(int i = 0; i < n; ++i){
            mark[s[i]-'a'] = true;
        }
        
        for(int k = 0; k < 26; ++k){
            if(!mark[k]){
                return false;
            }
        }
        
        return true;
    }
};