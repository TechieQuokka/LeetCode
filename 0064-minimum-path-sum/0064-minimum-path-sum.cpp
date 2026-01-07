class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int width = grid.size();
        int height = grid[0].size();

        for (int index = 1; index < height; index++) {

            grid[0][index] += grid[0][index - 1];
        }

        for (int index = 1; index < width; index++) {

            grid[index][0] += grid[index - 1][0];
        }

        for (int row = 1; row < width; row++) {
            for (int column = 1; column < height; column++) {

                grid[row][column] += min (grid[row-1][column], grid[row][column-1]);
            }
        }

        return grid[width - 1][height - 1];
    }
};