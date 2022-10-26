typedef unordered_map<int,int> uom;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        uom U{{0,0}};
        int sum = 0, n = size(nums);
        for(int i = 0; i < n; ++i){
            sum += nums[i];
            if(U.find(sum % k) == U.end()){
                U[sum % k] = i + 1;
            }
            else if(U[sum % k] < i){
                return true;
            }
        }
        return false;
    }
};