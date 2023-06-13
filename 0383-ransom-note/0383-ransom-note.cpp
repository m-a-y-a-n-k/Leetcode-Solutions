class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26,0);
        
        int n = ransomNote.size();
        for(int i = 0; i < n; i++){
            freq[ransomNote[i]-'a']++;
        }
        n = magazine.size();
        for(int i = 0; i < n; i++){
            freq[magazine[i]-'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                return false;
            }
        }
        return true;
    }
};