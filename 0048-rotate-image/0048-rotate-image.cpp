class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int size = matrix.size();
        vector<vector<int>> result (size, vector<int> (size, 0));

        for (int row = 0; row < size; row++) {
            for (int column = 0; column < size; column++) {

                result[column][size - row - 1] = matrix[row][column];
            }
        }

        matrix = result;
        return;
    }
};