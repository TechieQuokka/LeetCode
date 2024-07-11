struct LocationType {
    
    int row, column;
};

class Solution {
private:
    bool CheckNumber (vector<vector<char>>& board, int row, int column, int number) {
    
        // check row
        for (int index = 0; index < 9; index++) {
            
            if (this->ToInteger (board[row][index]) == number) return false;
        }
        
        // check column
        for (int index = 0; index < 9; index++) {
            
            if (this->ToInteger (board[index][column]) == number) return false;
        }
        
        // check 3 * 3 range
        int rowStart = (int) (row / 3) * 3, columnStart = (int) (column / 3) * 3;
        int rowEnd = rowStart + 3, columnEnd = columnStart + 3;
        for (int horizontal = rowStart; horizontal < rowEnd; horizontal++) {
            for (int vertial = columnStart; vertial < columnEnd; vertial++) {
                
                if (this->ToInteger (board[horizontal][vertial]) == number) return false;
            }
        }
        
        return true;
    }

    bool Sudoku (vector<vector<char>>& board, deque<struct LocationType>& location, struct LocationType current) {
        
        if (location.size() == 0) return false;
        
        for (int number = 1; number < 10; number++) {
            
            if (!this->CheckNumber(board, current.row, current.column, number)) continue;
            
            board[current.row][current.column] = this->ToCharacter (number);
            struct LocationType pivot = location.front();
            location.pop_front();
            bool result = this->Sudoku (board, location, pivot);
            if (result == false) return false;
            
            board[current.row][current.column] = '.';
            location.push_front(pivot);
        }
        return true;
    }

    char ToCharacter (int integer) {

        return integer + '0';
    }

    int ToInteger (char character) {

        if (character == '.') return 0;
        return character - '0';
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        
        deque<struct LocationType> location;

        for (int horizontal = 0; horizontal < 9; horizontal++) {
            for (int vertical = 0; vertical < 9; vertical++) {
                
                char element = board[horizontal][vertical];
                if (element == '.') location.push_back({horizontal, vertical});
            }
        }

        location.push_back ({8, 8});

        struct LocationType current = location.front(); location.pop_front();
        this->Sudoku (board, location, current);
        return;
    }
};