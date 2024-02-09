class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int limit = t - 3000;
        Q.push(t);
        while (Q.front() < limit) Q.pop();
        return Q.size();
    }
    private:
    queue<int>Q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */