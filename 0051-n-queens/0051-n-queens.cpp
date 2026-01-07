class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> answer;
        vector<int> buffer(n);
        fill (begin(check), end(check), false);
        NQueen (buffer, 0, n, answer);

        return answer;
    }

private:
    void NQueen (vector<int>& buffer, int depth, const int number, vector<vector<string>>& outResult) {

        if (depth == number) {

            outResult.push_back (buildBoard (buffer));
            return;
        }

        for (int index = 0; index < number; index++) {

            if (check[index]) continue;
            if (!checkBoard (buffer, depth, index)) continue;

            buffer[depth] = index;
            check[index] = true;
            NQueen (buffer, depth + 1, number, outResult);
            check[index] = false;
        }

        return;
    }

    bool checkBoard (vector<int>& buffer, int row, int column) {

        for (int x = 0; x < row; x++) {

            int y = buffer[x];

            if (x - y == row - column) return false;
            if (x + y == row + column) return false;

        }
        return true;
    }

    vector<string> buildBoard (vector<int>& buffer) {

        vector<string> result;
        int length = buffer.size();
        
        for (int row = 0; row < length; row++) {
            string line = "";
            for (int column = 0; column < length; column++) {
                if (buffer[row] == column) {
                    line += 'Q';
                } else {
                    line += '.';
                }
            }
            result.push_back(line);
        }
        
        return result;
    }

private:
    bool check[16];
};