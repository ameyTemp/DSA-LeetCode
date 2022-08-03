class MyCalendar {
public:
    set<pair<int,int>> arr;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto temp = arr.lower_bound({start,end});
        if(temp!=arr.end() and end>temp->first) return false;
        
        if(temp!=arr.begin() and start<(--temp)->second) return false;
        
        arr.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */