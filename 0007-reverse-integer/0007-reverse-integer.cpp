class Solution {
private:
    void IntegerToString (int number, char* buffer) {

        if (buffer == NULL) return;

        int pivot = pow (10, (int) log10 (number)), index = 0;
        while (pivot != 0) {

            int element = number / pivot;
            buffer[index++] = element + '0';
            number -= element * pivot;
            pivot /= 10;
        }
        buffer[index] = '\0';
        return;
    }

    long long StringToInteger (char* buffer, int length) {

        if (buffer == NULL) return -1;

        long long result = 0;
        for (int index = 0; index < length; index++) {

            result *= 10LL;
            result += (long long)(buffer[index] - '0');
        }
        return result;
    }

    void Swap (char* left, char* right) {

        int temp = *left;
        *left = *right;
        *right = temp;
        return;
    }

    void Palindrome (char* buffer, int length) {

        int left = 0, right = length - 1;
        while (left < right) {

            Swap (buffer + left, buffer + right);
            left++, right--;
        }
        return;
    }

public:
    int reverse(int x) {

        if (x == 0) return 0;
        
        long long sign = x < 0 ? -1 : 1;

        x = abs (x);

        char buffer[128] = { 0, };
        IntegerToString (x, buffer);

        cout << buffer << endl;
        int length = strlen (buffer);
        Palindrome (buffer, length);

        cout << buffer << endl;
        auto result = StringToInteger (buffer, length);
        if (result > 2147483647) return 0;
        return result * sign;
    }
};