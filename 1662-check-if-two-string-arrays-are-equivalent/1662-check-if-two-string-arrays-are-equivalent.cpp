class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n = word1.size(), m = word2.size();
        int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
        
        for(; i1 < n && i2 < m; ){
            if(word1[i1][j1] != word2[i2][j2]){
                return false;
            }
            j1++;
            j2++;
            if(j1 == word1[i1].size()){
                i1++;
                j1 = 0;
            }
            if(j2 == word2[i2].size()){
                i2++;
                j2 = 0;
            }
        }
        
        return i1 == n && i2 == m;
    }
};