class Solution {
private:
    bool IsDigit (char character) {

        return character >= '0' && character <= '9';
    }
public:
    int myAtoi(string source) {
        
        int start = 0, sign = 1, count = 0;
        long long int result = 0;
        int length = source.length();
        for (start = 0; start < length; start++) if (source[start] != ' ') break;
        for (start; start < length; start++) if (source[start] != '0') break;
        if (start > 0 && source[start - 1] == '0' && source[start] == '-') return 0;
        if (start > 0 && source[start - 1] == '0' && source[start] == '+') return 0;

        if (source[start] == '-') start++, sign = -1;
        else if (source[start] == '+') start++, sign = 1;
        for (start; start < length; start++) if (source[start] != '0') break;
        
        for (int index = start; index < length && count < 11; index++) {

            char element = source[index];
            if (!this->IsDigit (element)) break;

            result *= 10;
            result += (long long)(element - '0');
            count++;
        }
        if (result > INT_MAX) return sign == 1 ? 2147483647 : -2147483648;
        return result * sign;
    }
};