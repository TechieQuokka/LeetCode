class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        char startCharacter = word[0];
        int horizontal = board.size();
        int vertical = board[0].size();

        int wordLength = word.size();
        bool result = false;
        for (int row = 0; row < horizontal; row++) {
            for (int column = 0; column < vertical; column++) {
                if (board[row][column] != startCharacter) continue;

                vector<vector<int>> isVisited (horizontal, vector<int> (vertical, 0));
                result |= DepthFirstSearch (board, isVisited, horizontal, vertical, row, column, word, wordLength, 0);
                cout << "\n";
            }
        }
        return result;
    }

private:
    bool DepthFirstSearch (vector<vector<char>>& board, vector<vector<int>>& isVisited, int row, int column, int x, int y, string& word, int wordLength, int depth) {

        if (x < 0 || y < 0 || x == row || y == column) return false;
        if (isVisited[x][y] > 0) return false;
        if (board[x][y] != word[depth]) return false;
        isVisited[x][y] = 1;

        if (depth == wordLength - 1) return true;

        cout << board[x][y] << ' ';

        bool result = false;
        result |= DepthFirstSearch (board, isVisited, row, column, x + 1, y, word, wordLength, depth + 1);
        result |= DepthFirstSearch (board, isVisited, row, column, x - 1, y, word, wordLength, depth + 1);
        result |= DepthFirstSearch (board, isVisited, row, column, x, y + 1, word, wordLength, depth + 1);
        result |= DepthFirstSearch (board, isVisited, row, column, x, y - 1, word, wordLength, depth + 1);

        isVisited[x][y] = 0;
        return result;
    }
};