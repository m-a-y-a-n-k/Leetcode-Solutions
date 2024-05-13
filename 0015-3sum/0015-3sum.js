/**
 * @param {number[]} nums
 * @return {number[][]}
 */

var threeSum = function(nums) {
    nums.sort((a, b) => a - b);
    const triplets = [];
    
    for(let i = 0; i < nums.length; i++){
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        let j = i + 1;
        let k = nums.length - 1;
        
        while( j < k ){
            const total = nums[i] + nums[j] + nums[k];
            if(total > 0){
                k--;
            } else if(total < 0){
                j++;
            } else {
                triplets.push([nums[i], nums[j], nums[k]]);
                j++;
                
                while(nums[j] == nums[j-1] && j < k){
                    j++;
                }
            }
        }
    }
    return triplets;
};