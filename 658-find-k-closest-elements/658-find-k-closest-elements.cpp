class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        int n = size(arr);
        int idx = lower_bound(begin(arr),end(arr), x) - begin(arr);
        int start = idx - 1, end = idx;
        
        while(k--){
            int z = INT_MAX, y = INT_MAX;
            if(start >= 0){
                z = abs(arr[start] - x);
            }
            if(end < n){
                y = abs(arr[end] - x);
            }
            
            if(z <= y){
                if(start >= 0)
                    result.push_back(arr[start--]);
            } else {
                if(end < n)
                    result.push_back(arr[end++]);
            }            
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};