class MyCalendarThree {
    map<int,int> events;
    int ans;
public:
    MyCalendarThree() {
        ans = 0;
    }
    
    int book(int start, int end) {
        events[start]++;
        events[end]--;
            
        int ec = 0;
        for(auto &[t, c]: events){
            ec += c;
            ans = max(ans, ec);
        }
        
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */