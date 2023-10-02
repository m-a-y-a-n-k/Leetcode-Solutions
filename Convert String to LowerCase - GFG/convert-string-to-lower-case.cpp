//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string toLower(string S) {
        // code here
        string result = "";
        for(char ch: S){
            if(ch >= 'A' && ch <= 'Z'){
                result.push_back((char)(ch + 32));
            } else {
                result.push_back(ch);
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.toLower(S) << endl;
    }
    return 0;
}

// } Driver Code Ends