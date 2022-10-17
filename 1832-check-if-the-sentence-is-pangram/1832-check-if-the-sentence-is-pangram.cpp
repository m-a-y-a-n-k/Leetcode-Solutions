class Solution {
public:
    bool checkIfPangram(string s) {
        int n = size(s);
        bitset<26> mark;

        for(int i = 0; i < n; ++i){
            mark.set(s[i] - 'a');
        }
        
        return mark.count() == 26;
    }
};