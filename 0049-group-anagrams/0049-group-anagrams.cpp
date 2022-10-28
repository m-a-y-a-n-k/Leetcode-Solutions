class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        
        map<vector<int>,vector<string>> vm;
        
        for(auto &str: strs){
            vector<int> f(26, 0);
            for(int i = 0; i < str.size(); ++i){
                f[str[i]-'a']++;
            }
            vm[f].push_back(str);
        }
        
        for(auto &[_, sv]: vm){
            result.push_back(sv);
        }
        
        return result;
    }
};