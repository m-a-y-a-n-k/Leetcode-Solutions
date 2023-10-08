//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string transform(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<transform(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends



string transform(string s)
{
    // code here
    string result = "";
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(i == 0 || s[i-1] == ' ' && s[i] != ' '){
            if(s[i] >= 'a' && s[i] <= 'z'){
                result += (s[i] - 32);
            } else {
                result += s[i];
            }
        } else {
            result += s[i];
        }
    }
    
    return result;
}