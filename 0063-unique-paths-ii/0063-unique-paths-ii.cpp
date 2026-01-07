class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        if (obstacleGrid[0][0] == 1) return 0;
        
        int width = obstacleGrid.size();
        int height = obstacleGrid[0].size();
        for (int row = 0; row < width; row++) {
            for (int column = 0; column < height; column++) {

                obstacleGrid[row][column] *= -1;
            }
        }
        obstacleGrid[0][0] = 1;

        for (int row = 0; row < width; row++) {
            for (int column = 0; column < height; column++) {

                if (row == 0 && column == 0) continue;
                if (obstacleGrid[row][column] == -1) continue;

                int top = 0, left = 0;
                if (row <= 0 || obstacleGrid[row - 1][column] == -1) top = 0;
                else top = obstacleGrid[row - 1][column];

                if (column <= 0 || obstacleGrid[row][column - 1] == -1) left = 0;
                else left = obstacleGrid[row][column - 1];

                
                obstacleGrid[row][column] = top + left;
            }
        }

        int answer = obstacleGrid[width - 1][height - 1];
        return answer < 0 ? 0 : answer;
    }
};