#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string word, result = "";
        
        while(getline(ss, word, ' ')){
            reverse(begin(word), end(word));
            result += (word);
            result.push_back(' ');
        }
        result.pop_back();
        return result;
    }
};