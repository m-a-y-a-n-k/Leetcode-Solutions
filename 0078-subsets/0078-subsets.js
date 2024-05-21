/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    
    const n = nums.length;
    const res = [];
    
    function backtrack(currIdx, curr){
        res.push([...curr]);
        
        for(let idx = currIdx; idx < n; ++idx){
            curr.push(nums[idx]);
            backtrack(idx + 1, curr);
            curr.pop();
        }
    }
    
    backtrack(0, []);
    return res;
};