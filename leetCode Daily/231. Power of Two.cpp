class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
        return false;
        int x = log2(n);
        double y = log2(n);
        return x==y;
    }
};
