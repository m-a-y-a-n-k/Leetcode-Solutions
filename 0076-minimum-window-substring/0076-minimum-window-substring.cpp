class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = size(s), m = size(t);
        
        if(m > n || n == 0 || m == 0){
            return "";
        }
        
        const int CHAR_SIZE = 256;
        
        int hash_str[CHAR_SIZE] = {0}, hash_ptr[CHAR_SIZE] = {0};
        
        for(int i = 0; i < m; ++i){
            hash_ptr[t[i]]++;
        }
        
        int i = 0, start = -1, min_len = INT_MAX, count = 0; 
        
        for(int j = 0; j < n; ++j){
            hash_str[s[j]]++;
            
            if(hash_str[s[j]] <= hash_ptr[s[j]]){
                count++;
            }
            
            if(count == m){
                
                while(hash_str[s[i]] > hash_ptr[s[i]] || hash_ptr[s[i]] == 0){
                    if(hash_str[s[i]] > hash_ptr[s[i]])
                        --hash_str[s[i]];
                    ++i;
                }
                
                int len = j - i + 1;
                if(len < min_len){
                    min_len = len;
                    start = i;
                }
            }
        }
        
        if(start == -1){
            return "";
        }
        
        return s.substr(start, min_len);
    }
};