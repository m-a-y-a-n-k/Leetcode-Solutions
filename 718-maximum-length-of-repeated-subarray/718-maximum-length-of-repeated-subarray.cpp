class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = size(nums1), n2 = size(nums2), ans = 0;
        
        vector<int> dp(n2 + 1, 0);
        
        for(int i = 0; i < n1; ++i){            
            for(int j = n2 - 1; j >= 0; --j){
                if(nums1[i] == nums2[j]){
                    dp[j + 1] = 1 + dp[j];
                } else {
                    dp[j + 1] = 0;
                }
                ans = max(ans, dp[j + 1]);
            }
        }
        
        return ans;
    }
};