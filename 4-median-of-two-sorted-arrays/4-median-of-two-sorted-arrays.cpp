typedef long long ll;

class Solution
{
    double solve(vector<int> &nums1, vector<int> &nums2, int n, int m)
    {
        int total = n + m;
        int half = total / 2;
        int i = 0, j = 0;
        for(; j < m && i < n && half > 0;){
            if(nums1[i] <= nums2[j]){
                i++;
            } else {
                j++;
            }
            half--;
        }
        
        while(i < n && half > 0){
            i++;
            half--;
        }
        while(j < m && half > 0){
            j++;
            half--;
        }
        
        double right = INFINITY;
        if(i < n && j < m){
            right = min(nums1[i], nums2[j]);
        } else if(i < n){
            right = nums1[i];
        } else if(j < m){
            right = nums2[j];
        }
        double left = -INFINITY;
        if(i - 1 >= 0 && j - 1 >= 0){
            left = max(nums1[i-1], nums2[j-1]);
        } else if(i - 1 >= 0){
            left = nums1[i-1];
        } else if(j - 1 >= 0){
            left = nums2[j-1];
        }
        
        if(total%2){
            return right;
        } 
        return (left + right)/2.0;    
    }

    public:
        double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
        {
            int n = size(nums1), m = size(nums2);
            return solve(nums1, nums2, n, m);
        }
};