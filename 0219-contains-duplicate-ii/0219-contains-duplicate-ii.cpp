#define uom unordered_map

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        if(k == 0){
            return false;
        }
        
        uom<int,int> U;
        
        int i = 0, n = size(nums);
                
        for(; i < n; ++i){
            if(U.find(nums[i]) != U.end()){
                if(i - U[nums[i]] <= k)
                    return true;
            }
            U[nums[i]] = i;
        }
        
        return false;
    }
};