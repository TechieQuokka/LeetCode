class NumMatrix {
private:
    vector<vector<int>> table;

public:
    NumMatrix(vector<vector<int>>& matrix) : table (matrix.size() + 1, vector<int> (matrix[0].size() + 1, 0)) {
        
        int horizontal = matrix.size(), vertical = matrix[0].size();
        for (int row = 0; row < horizontal; row++) {
            for (int column = 0; column < vertical; column++) {

                this->table[row + 1][column + 1] = this->table[row + 1][column] + this->table[row][column + 1] - this->table[row][column] + matrix[row][column];
            }
        }
        return;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int result[4] = { 0, };
        result[0] = this->table[row2 + 1][col2 + 1];
        result[1] = this->table[row1][col1];
        result[2] = this->table[row1][col2 + 1];
        result[3] = this->table[row2 + 1][col1];

        return result[0] - (result[2] + result[3]) + result[1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */