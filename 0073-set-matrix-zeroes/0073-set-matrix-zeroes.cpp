class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int width = matrix.size();
        int height = matrix[0].size();

        queue<pair<int, int>> coordinate;
        for (int row = 0; row < width; row++) {
            for (int column = 0; column < height; column++) {

                if (matrix[row][column] == 0) coordinate.push ({row, column});
            }
        }

        while (coordinate.empty() == false) {

            auto data = coordinate.front(); coordinate.pop();
            int row = data.first, column = data.second;

            for (int index = 0; index < height; index++) {

                matrix[row][index] = 0;
            }

            for (int index = 0; index < width; index++) {

                matrix[index][column] = 0;
            }
        }

        return;
    }
};