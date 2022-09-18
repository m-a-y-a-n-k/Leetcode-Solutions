class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> M;
        int n = s.size(), mx = 0, l = 0;
        
        // abcdefchijkfqraxj
        // 10
        int j = 0;
        for(int i = 0; i < n; i++){
            if(M.find(s[i]) != M.end() && M[s[i]] >= j){
                j = M[s[i]];
                l = (i + 1) - j;
            } else {
                l++;
            }
            mx = max(l,mx);
            M[s[i]] = i + 1;
        }
        return mx;
    }
};