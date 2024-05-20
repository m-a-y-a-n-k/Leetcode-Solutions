/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    const n = nums.length;
    
    if(n == 1){
        return nums[0];
    }
    
    const ans = Array(n).fill(0);
    ans[0] = nums[0];
    ans[1] = Math.max(nums[0], nums[1]);
    
    for(let i = 2; i < n; ++i){
        ans[i] = Math.max(ans[i-1], ans[i-2] + nums[i]);
    } 
    
    return ans[n-1];
};