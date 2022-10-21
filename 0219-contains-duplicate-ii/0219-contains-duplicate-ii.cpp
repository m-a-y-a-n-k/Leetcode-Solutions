#define uom unordered_map

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        if(k == 0){
            return false;
        }
        
        uom<int,int> U;
        
        int i = 0, n = size(nums);
        
        for(; i < k && i < n; ++i){
            if(U[nums[i]] == 1)
                return true;
            U[nums[i]] = 1;
        }
        
        for(; i < n; ++i){
            if(U[nums[i]] == 1)
                return true;
            U[nums[i-k]] = 0;
            U[nums[i]] = 1;
        }
        
        return false;
    }
};