class Solution {
public:
    string breakPalindrome(string p) {
        int n = p.size();
        if(n <= 1){
            return "";
        }
        
        bool u = true;
        for(int i = 0; i < n/2; ++i){
            if(p[i] != 'a'){
                p[i] = 'a';
                u = false;
                break;
            }
        }
        
        if(u){
            p[n-1] = 'b';
        }
        
        return p;
    }
};