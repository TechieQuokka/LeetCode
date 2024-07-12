class Solution {
public:
    vector<vector<int>> generateMatrix(int number) {
        
        vector<vector<int>> matrix (number, vector<int> (number, 0));

        int row_start = 0, column_start = 0;
        int row_end = number, column_end = number;
        int row_index = 0, column_index = 0;
        int pivot = 0, sign = 1, count = 0, size = row_end * column_end;
        while (true) {
            for (int repeat = row_start; repeat < row_end; repeat++, count++) {

                int index = row_index;
                row_index += sign;
                matrix[pivot][index] = count + 1;
            }
            if (count == size) break;

            row_index -= sign;
            pivot = row_index;
            column_index += sign;

            for (int repeat = column_start + 1; repeat < column_end; repeat++, count++) {

                int index = column_index;
                column_index += sign;
                matrix[index][pivot] = count + 1;
            }
            if (count == size) break;

            column_index -= sign;
            pivot = column_index;

            sign *= -1;
            row_index += sign;

            row_start++, column_start++;
        }

        return matrix;
    }
};