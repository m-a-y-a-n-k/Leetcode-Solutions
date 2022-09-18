class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> M;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(M.find(nums[i]) != M.end()){
                return {M[nums[i]],i};
            }
            M[target-nums[i]] = i;
        }
        return {-1,-1};
    }
};