class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if (dividend == INT_MIN && divisor == 1 || dividend == INT_MIN && divisor == -1) return divisor == 1 ? INT_MIN : INT_MAX;
        return dividend / divisor;
    }
};