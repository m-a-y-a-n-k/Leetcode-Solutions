//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
    bool isVowel(char ch){
        return (
            ch == 'a' ||
            ch == 'e' ||
            ch == 'i' ||
            ch == 'o' ||
            ch == 'u'
        );
    }
    
    void swapChars(string &s, int i, int j){
        char ch = s[i];
        s[i] = s[j];
        s[j] = ch;
    }
    
    public:
        string modify (string s)
        {
            //code here.
            int n = s.size();
            for(int i = 0, j = n - 1; i < j; ){
                if(!isVowel(s[i])){
                    i++;
                } else if(!isVowel(s[j])){
                    j--;
                } else {
                    swapChars(s, i, j);
                    i++;
                    j--;
                }
            }
            return s;
        }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.modify (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends