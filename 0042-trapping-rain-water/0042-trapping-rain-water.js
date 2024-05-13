/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let left = 0, right = height.length - 1;
    let leftMax = height[left], rightMax = height[right];    
    let ans = 0;
    while(left < right){
        if(leftMax <= rightMax){
            ans += leftMax - height[left];
            left++;
            leftMax = Math.max(leftMax, height[left]);
        } else {
            ans += rightMax - height[right];
            right--;
            rightMax = Math.max(rightMax, height[right]);
        }
    }
    return ans;
};