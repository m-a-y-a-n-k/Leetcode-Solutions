typedef unordered_map<int,int> uom;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int s = 0, i = 1, x = 0;
        
        uom U;
        
        for(auto &k: nums){
            if(U[k] > 0){
                x = k;
            }
            U[k] = 1;
            s += i - k;
            ++i;
        }
        
        return {x, s + x};
    }
};