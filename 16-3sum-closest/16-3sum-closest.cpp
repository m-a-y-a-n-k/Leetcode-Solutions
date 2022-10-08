class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(begin(nums), end(nums));
        
        int ans = 1000000, n = size(nums);
        
        for(int i = 0; i < n - 2; ++i){
            
            int j = i + 1, k = n - 1;
            int closest = 1000000;
            
            while(j < k){
                
                int sum = nums[i] + nums[j] + nums[k];
                
                if(abs(target - sum) < abs(target - closest)){
                    closest = sum;
                }
                
                if(target > sum){
                    ++j;
                } else if(target < sum){
                    --k;
                } else {
                    return sum;
                }
            }
            
            if(abs(target - ans) > abs(target - closest)){
                ans = closest;
            }
        }
        
        return ans;
    }
};