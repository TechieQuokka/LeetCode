#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) return false;
            
        double length = log10 (x);
        if (floor(length) == 0) return true;

        int pivot = pow (10, floor(length));
        
        while (x != 0) {

            int left = x / pivot;
            int right = x % 10;
            x = x - (left * pivot);
            x /= 10;
            pivot /= 100;

            if (left != right) return false;
        }

        return true;
    }
};