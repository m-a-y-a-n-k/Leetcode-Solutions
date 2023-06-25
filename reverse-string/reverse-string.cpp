class Solution {
    void reverse(vector<char> &s, int start, int end){
        if(start >= end){
            return ;
        }
        swap(s[start], s[end]);
        reverse(s, start + 1, end - 1);
    }
public:
    void reverseString(vector<char>& s) {
        reverse(s, 0, s.size() - 1);
    }
};