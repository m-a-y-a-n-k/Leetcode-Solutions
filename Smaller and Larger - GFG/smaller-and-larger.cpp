//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int search(int arr[], int start, int end, int value){
        for(int i = start; i <= end; i++){
            if(arr[i] > value){
                return i;
            }
        }
        return end + 1;
    }
    
	vector<int> getMoreAndLess(int arr[], int n, int x) {
	    // code here
	    int valueIdx = search(arr, 0, n-1, x);
	    int lessEquals = valueIdx;
	    int idx = valueIdx - 1;
	    for(; idx >= 0; idx--){
	        if(arr[idx] < x){
	            break;
	        }
	    }
	    int moreEquals = n - idx - 1;
	    return {lessEquals, moreEquals};
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMoreAndLess(arr, n, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}

// } Driver Code Ends