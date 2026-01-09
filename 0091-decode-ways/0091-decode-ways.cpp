class Solution {
public:
    int numDecodings(string s) {
        
        vector<int> table (s.length() + 1);
        return numDecodings (s, table, 0);
    }

private:
    int numDecodings (string& source, vector<int>& table, int index) {

        if (table[index] != 0) return table[index];

        if (index == source.length()) return table[index] = 1;
        if (source[index] == '0') return table[index] = 0;

        int ways = numDecodings (source, table, index + 1);
        if (index + 1 >= source.length()) return table[index] = ways;

        int first = source[index] - '0';
        int second = source[index + 1] - '0';
        int twoDigit = first * 10 + second;
        if (twoDigit >= 10 && twoDigit <= 26) {

            ways += numDecodings (source, table, index + 2);
        }

        return table[index] = ways;
    }
};