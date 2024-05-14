/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    
    let left = 0, right = height.length - 1;
    let maxArea = 0;
    
    while(left < right){
        if(height[left] <= height[right]){
            maxArea = Math.max(maxArea, height[left] * (right - left));
            left++;
        } else {
            maxArea = Math.max(maxArea, height[right] * (right - left));
            right--;
        }
    }
    
    return maxArea;
};