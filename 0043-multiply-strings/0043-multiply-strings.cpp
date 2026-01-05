class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0") return "0";
        
        string answer = "0";

        int place = 0;
        for (int i = num1.length() - 1; i >= 0; i--, place++) {

            string buffer = "";
            int carry = 0;
            for (int j = num2.length() - 1; j >= 0; j--) {

                int operand1 = num1[i] - '0';
                int operand2 = num2[j] - '0';

                int calculate = operand1 * operand2 + carry;
                buffer += digitToCharacter (calculate % 10);
                carry = calculate / 10;
            }

            if (carry != 0) buffer += digitToCharacter (carry);

            reverse(buffer.begin(), buffer.end());
            answer = sum (answer, buffer + makeZeroString (place));
        }

        return answer;
    }

    string sum (string num1, string num2) {

        if (num1.length() < num2.length()) Swap (num1, num2);

        string result = "";

        int top = num1.length() - 1, bottom = num2.length() - 1;
        int carry = 0;
        for (int loop = num2.length(); loop > 0; loop--) {

            int operand1 = num1[top--] - '0';
            int operand2 = num2[bottom--] - '0';

            int calculate = operand1 + operand2 + carry;
            carry = calculate / 10;

            result += digitToCharacter (calculate % 10);
        }

        for (int index = top; index >= 0; index--) {

            int operand = num1[index] - '0';
            int calculate = operand + carry;
            carry = calculate / 10;

            result += digitToCharacter (calculate % 10);
        }

        if (carry != 0) result += digitToCharacter (carry);

        reverse (result.begin(), result.end());
        return result;
    }

private:
    void Swap (string& left, string& right) {

        string temp = left;
        left = right;
        right = temp;
        return;
    }

    char digitToCharacter (int digit) {

        return digit + '0';
    }

    string makeZeroString (int count) {

        string result = "";
        for (int loop = 0; loop < count; loop++) {

            result += '0';
        }
        return result;
    }
};