#define ump unordered_map

class TimeMap {
    ump<string, ump<int,string>> KTV;
    ump<string, vector<int>> KTM;
    
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        KTV[key][timestamp] = value;
        KTM[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        
        int t = -1;
        int l = 0, r = KTM[key].size() - 1;
        
        while(l <= r){
            int mid = (l + r)/2;
            if(KTM[key][mid] <= timestamp){
                l = mid + 1;
                t = KTM[key][mid];
            } else {
                r = mid - 1;
            }
        }
        
        if(t != -1){
            return KTV[key][t];
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */