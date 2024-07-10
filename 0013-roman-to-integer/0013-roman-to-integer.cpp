class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> table = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };

        int result = 0, length = s.length();
        for (int index = 0; index < length; index++) {

            int current = s[index], next = index < length ? s[index + 1] : '\0';
            int flag = 0;

            if (current == 'I') {
                if (next == 'V' || next == 'X') result += table[next] - table[current], flag = 1;
            }
            else if (current == 'X') {
                if (next == 'L' || next == 'C') result += table[next] - table[current], flag = 1;
            }
            else if (current == 'C') {
                if (next == 'D' || next == 'M') result += table[next] - table[current], flag = 1;
            }

            if (flag == 1) {

                index++;
                continue;
            }

            result += table[current];
        }
        return result;
    }
};