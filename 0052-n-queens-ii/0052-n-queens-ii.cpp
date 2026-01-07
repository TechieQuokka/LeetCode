class Solution {
public:
    int totalNQueens(int n) {
        
        vector<int> buffer (n);
        return NQueen (buffer, 0, n);
    }

private:
    int NQueen (vector<int>& buffer, int depth, const int number) {

        if (depth == number) return 1;

        int count = 0;
        for (int index = 0; index < number; index++) {

            if (check[index]) continue;
            if (!checkBoard (buffer, depth, index)) continue;

            buffer[depth] = index;
            check[index] = true;
            count += NQueen (buffer, depth + 1, number);
            check[index] = false;
        }

        return count;
    }

    bool checkBoard (vector<int>& buffer, int row, int column) {

        for (int x = 0; x < row; x++) {

            int y = buffer[x];

            if (x - y == row - column) return false;
            if (x + y == row + column) return false;

        }
        return true;
    }

private:
    bool check[16];
};