typedef pair<int,string> sf;
class CompareString{
    public: 
        bool operator()(const sf& A, const sf& B){
            if(A.first == B.first){
                return A.second > B.second;
            }
            return A.first < B.first;
        }    
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(auto word: words){
            freq[word]++;
        }
        priority_queue<sf, vector<sf>, CompareString> pq;
        for(auto e: freq){
            pq.push({e.second,e.first});
        }
        int cnt = 0;
        vector<string> result;
        while(!pq.empty() && cnt < k){
            result.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        if(cnt == k)
            return result;
        return {};
    }
};