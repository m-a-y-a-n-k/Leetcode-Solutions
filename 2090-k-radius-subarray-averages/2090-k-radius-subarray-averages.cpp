class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> avgs(n, -1);
        if(n <= 2*k){
            return avgs;
        }
        long long sum = 0;
        int left = 0, right = 2*k;
        for(int i = 0; i <= right; i++){
            sum += nums[i];
        }
        for(; right < n; ){
            avgs[left + k] = (int)(sum / (2*k + 1));
            if(right == n-1){
                break;
            }
            sum += nums[++right];
            sum -= nums[left++];
        }
        return avgs;
    }
};