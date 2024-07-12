class Solution {
public:
    int fib(int number) {
        
        if (number < 2) return number;
        return fib(number - 1) + fib(number - 2);
    }
};