class Solution {
public:
    int fib(int number) {
        
        static int buffer[64] = { 0, };
        if (buffer[number]) return buffer[number];
        if (number < 2) return number;
        return buffer[number] = fib(number - 1) + fib(number - 2);
    }
};