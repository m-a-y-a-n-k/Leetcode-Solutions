typedef long long ll;

class Solution {
public:
    const int mod = 1e9 + 7;

    int concatenatedBinary(int n) {
        ll ans = 0, len = 0;
        
        for(int i = 1; i <= n; i++){
            if((i&(i-1))==0){
                len++;
            }
            ans = ((ans<<len)%mod + i%mod)%mod;
        }
        
        return (ans + mod)%mod;
    }
};