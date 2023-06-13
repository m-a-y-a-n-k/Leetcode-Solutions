class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        vector<int> digi;
        while(x > 0){
            int d = x % 10;
            digi.push_back(d);
            x /= 10;
        }
        for(int i = 0; i < digi.size()/2; ++i){
            if(digi[i] != digi[digi.size()-1-i]){
                return false;
            }
        }
        return true;
    }
};