class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> sums;
        int sum = 0;
        for(auto &num: nums){
            if((num&1)==0){
                sum += num;
            }
        }
        
        for(auto &q: queries){
            int v = q[0], i = q[1];
            nums[i] += v;
            if(((nums[i] - v)&1) == 0){
                sum += v;
                if(v&1){
                    sum -= nums[i];
                }
            } else {
                if(v&1){
                    sum += nums[i];
                }
            }
            sums.push_back(sum);
        }
        
        return sums;
    }
};