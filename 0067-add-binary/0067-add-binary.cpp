class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        
        string r = "";
        int c = 0, p = 0, v = 0;
        
        for(int i = m - 1, j = n - 1; i >= 0 || j >= 0; i--,j--){
            if(i >= 0 && j >= 0){
                if(a[i] == '0' && b[j] == '0'){
                    ;
                } else if(a[i] == '1' && b[j] == '1') {
                    c++;
                    p++;
                } else {
                    p++;
                }                
            } else if(i >= 0){
                p = a[i] - '0';   
            } else if(j >= 0){
                p = b[j] - '0';
            } else {
                p = 0;
            }
            v = p + c;
            c = v / 2;
            p = 0;
            r.push_back((v % 2) + '0');
        }
        
        if(c > 0){
            r.push_back(c + '0');
        }

        int k = r.size();
        string s = "";

        for(int m = k - 1; m >= 0; m--){
            s += r[m];
        }

        return s;
    }
    
    
};