int mem[101][27][101][101];

class Solution {
    string str;
    
    int solve(int i, int last, int cnt, int k){
        
        if(k < 0){
            return INT_MAX;
        }
        
        if(i >= str.size()){
            return 0;
        }
        
        if(mem[i][last][cnt][k] != -1){
            return mem[i][last][cnt][k];
        }
        
        int del = solve(i + 1, last, cnt, k - 1);
        int keep = 0;
        
        if(last == str[i] - 'a'){
            if(cnt == 1 || cnt == 9 || cnt == 99){
                keep = 1;
            }
            keep += solve(i + 1, last, cnt + 1, k);
        } else {
            keep = 1 + solve(i + 1, str[i] - 'a', 1, k);
        }
        
        return mem[i][last][cnt][k] = min(del, keep);
    }
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        str = s;
        memset(mem, -1, sizeof(mem));
        return solve(0, 26, 0, k);
    }
};