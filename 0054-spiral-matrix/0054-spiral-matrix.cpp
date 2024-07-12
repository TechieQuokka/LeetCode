class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> result;
        
        int row_start = 0, column_start = 0;
        int row_end = matrix[0].size(), column_end = matrix.size();
        int row_index = 0, column_index = 0;
        int pivot = 0, sign = 1, count = 0, size = row_end * column_end;
        while (true) {
            for (int repeat = row_start; repeat < row_end; repeat++, count++) {

                int index = row_index;
                row_index += sign;
                int current = matrix[pivot][index];

                result.push_back (current);
            }
            if (count == size) break;

            row_index -= sign;
            pivot = row_index;
            column_index += sign;

            for (int repeat = column_start + 1; repeat < column_end; repeat++, count++) {

                int index = column_index;
                column_index += sign;
                int current = matrix[index][pivot];

                result.push_back (current);
            }
            if (count == size) break;

            column_index -= sign;
            pivot = column_index;

            sign *= -1;
            row_index += sign;

            row_start++, column_start++;
        }
        return result;
    }
};