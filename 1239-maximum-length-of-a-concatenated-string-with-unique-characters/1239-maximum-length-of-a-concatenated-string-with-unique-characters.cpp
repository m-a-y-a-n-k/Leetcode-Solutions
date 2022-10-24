class Solution {
    // Turns |a| into a bitmask for each character present.
    //   Returns -1 if the characters are not unique.
    int bitmask(const string& a) {
        int ans = 0;
        for (char ch : a) {
            const int mask = 1 << (ch - 'a');
            if (ans & mask) return -1;
            ans |= mask;
        }
        return ans;
    }
public:
    int maxLength(const vector<string>& arr) {
        // Turn |arr| into bitmasks.
        vector<int> bms;
        bms.reserve(arr.size());
        for (const string& a : arr) {
            const int m = bitmask(a);
            if (m != -1) bms.push_back(m);
        }
        
        // Expand the bitmasks if there is no conflict.
        vector<int> as;
        for (int bm : bms) {
            int as_size = as.size();
            for (int i = 0; i < as_size; ++i)
                if (!(as[i] & bm)) as.push_back(as[i] | bm);
            as.push_back(bm);
        }
        
        // Look for the bitmask with the most bits set.
        int ans = 0;
        for (int a : as) ans = max(ans, __builtin_popcount(a));
        return ans;
    }
    
};