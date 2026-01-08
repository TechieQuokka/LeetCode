class Solution {
public:
    int climbStairs(int n) {
        
        return fibonacciSequence (n + 1);
    }

private:
    int fibonacciSequence (int number) {

        static int table[64] = { 0, };

        if (table[number]) return table[number];
        if (number < 2) return table[number] = number;
        return table[number] = fibonacciSequence (number - 1) + fibonacciSequence (number - 2);
    }
};