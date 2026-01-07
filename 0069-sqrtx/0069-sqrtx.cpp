class Solution {
public:
    int mySqrt(int x) {
        
        return square_root (x, 0, x);
    }

private:
    int square_root (long long x, long long left, long long right) {

        if (left > right) return right;

        long long middle = left + (right - left) / 2;
        long long power = middle * middle;
        if (power == x) return middle;
        else if (power < x) return square_root (x, middle + 1, right);
        else return square_root (x, left, middle - 1);
    }
};