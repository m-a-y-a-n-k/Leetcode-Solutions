class Solution {
    stack<string> words;
    string word;
    void addWord(char ch){
        if(ch != ' ')
            word.push_back(ch); 
    }
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        word = "";
        for(int i = 0; i < n; ++i){
            addWord(s[i]);
            if(s[i] == ' ' || i == n-1){
                if(word != ""){
                    words.push(word);
                }
                word = "";
                continue;
            }
        }
        if(words.size() > 0){
            return words.top().size();
        }
        return 0;
    }
};