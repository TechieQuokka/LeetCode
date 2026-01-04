class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        return check_horizontal (board) && check_vertical (board) && check_box (board);
    }

private:
    bool check_horizontal (vector<vector<char>>& board) {

        for (int row = 0; row < board.size(); row++) {

            set<char> buffer;
            for (int column = 0; column < board.size(); column++) {
                if(board[row][column] == '.') continue;
                if (buffer.contains(board[row][column])) return false;
                buffer.insert (board[row][column]);
            }
        }

        return true;
    }

    bool check_vertical (vector<vector<char>>& board) {

        for (int row = 0; row < board.size(); row++) {

            set<char> buffer;
            for (int column = 0; column < board.size(); column++) {
                if(board[column][row] == '.') continue;
                if (buffer.contains(board[column][row])) return false;
                buffer.insert (board[column][row]);
            }
        }

        return true;
    }

    bool check_box (vector<vector<char>>& board) {

        for (int row = 0; row < 3; row++) {
            for (int column = 0; column < 3; column++) {

                set<char> buffer;
                for (int width = 0; width < 3; width++) {
                    for (int height = 0; height < 3; height++) {

                        char element = board[row * 3 + width][column * 3 + height];
                        if (element == '.') continue;
                        if (buffer.contains(element)) return false;
                        buffer.insert (element);
                    }
                }
            }
        }

        return true;
    }
};