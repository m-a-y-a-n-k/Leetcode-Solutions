//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
// Driver program to test above function

// } Driver Code Ends
class Solution{
  public:
    /*you are required to complete this method*/
    int convertFive(int n)
    {
        //Your code here
        int result = 0;
        int count = 0;
        while(n > 0){
            int digit = n % 10;
            if(digit == 0){
                digit = 5;
            }
            result = digit * pow(10, count++) + result;
            n /= 10;
        }
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	Solution obj;
    	cout<<obj.convertFive(n)<<endl;
    }
}
// } Driver Code Ends