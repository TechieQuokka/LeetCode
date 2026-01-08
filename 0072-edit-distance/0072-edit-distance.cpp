class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int length1 = word1.length() + 1, length2 = word2.length() + 1;
        vector<vector<int>> table (length1, vector<int> (length2, 0));
        for (int index = 1; index < length1; index++) {

            table[index][0] = index;
        }
        for (int index = 0; index < length2; index++) {

            table[0][index] = index;
        }

        for (int row = 1; row < length1; row++) {
            for (int column = 1; column < length2; column++) {

                if (word1[row - 1] == word2[column - 1]) table[row][column] = table[row - 1][column - 1];
                else table[row][column] = 1 + minimum (table[row - 1][column - 1], table[row - 1][column], table[row][column - 1]);
            }
        }

        return table[length1 - 1][length2 - 1];
    }

private:
    int minimum (int first, int second, int third) {

        if (first > second) first = second;
        return first < third ? first : third;
    }
};