class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix_) {
        
        auto matrix = charToIntMatrix (matrix_);

        int answer = 0;
        for (int index = 0; index < matrix.size(); index++) {

            auto& row = matrix[index];
            if (index == 0) {

                answer = max (answer, largestRectangleArea (row));
                continue;
            }

            for (int column = 0; column < matrix[0].size(); column++) {

                if (matrix[index][column] == 0) continue;
                matrix[index][column] += matrix[index - 1][column];
            }

            answer = max (answer, largestRectangleArea (row));
        }

        return answer;
    }

private:
    int largestRectangleArea(vector<int> heights) {
        
        heights.push_back(0);
        stack<int> buffer;
        int maxArea = 0;

        int length = heights.size();
        for (int index = 0; index < length; index++) {
            while (buffer.empty() == false && heights[buffer.top()] > heights[index]) {

                int height = heights[buffer.top()]; buffer.pop();
                int width = 0;

                if (buffer.empty()) width = index;
                else width = index - buffer.top() - 1;

                int area = height * width;
                maxArea = max (maxArea, area);
            }

            buffer.push (index);
        }

        return maxArea;
    }

    vector<vector<int>> charToIntMatrix(const vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) return {};
        
        int cols = matrix[0].size();
        vector<vector<int>> result(rows, vector<int>(cols));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = matrix[i][j] - '0';
            }
        }
        
        return result;
    }
};