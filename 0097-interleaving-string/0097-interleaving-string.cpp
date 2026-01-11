class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int length1 = s1.length();
        int length2 = s2.length();

        if (length1 + length2 != s3.length()) return false;

        vector<vector<bool>> table (length1 + 1, vector<bool> (length2 + 1, false));

        table[0][0] = true;

        for (int index = 1; index <= length1; index++) {
            if (s1[index - 1] == s3[index - 1]) {

                table[index][0] = table[index - 1][0];
            }
        }

        for (int index = 1; index <= length2; index++) {
            if (s2[index - 1] == s3[index - 1]) {

                table[0][index] = table[0][index - 1];
            }
        }

        for (int row = 1; row <= length1; row++) {
            for (int column = 1; column <= length2; column++) {

                int pivot = row + column - 1;

                if (s1[row - 1] == s3[pivot]) {

                    table[row][column] = table[row][column] | table[row - 1][column];
                }
                if (s2[column - 1] == s3[pivot]) {

                    table[row][column] = table[row][column] | table[row][column - 1];
                }
            }
        }

        return table[length1][length2];
    }
};