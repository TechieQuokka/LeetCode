class Solution {
public:
    int uniquePaths(int n, int m) {
        
        vector<vector<int>> grid (n, vector<int> (m + 1, 0));
        for (int index = 0; index < m + 1; index++) grid[0][index] = 1;

        for (int row = 1; row < n; row++) {
            for (int column = 1; column < m + 1; column++) {

                grid[row][column] = grid[row - 1][column] + grid[row][column - 1];
            }
        }

        return grid[n - 1][m];
    }
};