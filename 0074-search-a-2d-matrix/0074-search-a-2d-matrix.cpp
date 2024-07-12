class Solution {
private:
    bool BinarySearch (vector<int>& source, int left, int right, int target) {

        if (left > right) return false;
        int middle = (left + right) / 2;

        if (source[middle] == target) return true;
        else if (source[middle] < target) return this->BinarySearch (source, middle + 1, right, target);
        else return this->BinarySearch (source, left, middle - 1, target);
    }

    int FindColumn (vector<vector<int>>& source, int left, int right, int target) {

        if (left >= right) return source[left][0] > target ? left - 1 : left;
        int middle = (left + right) / 2;

        if (source[middle][0] == target) return middle;
        else if (source[middle][0] < target) return this->FindColumn (source, middle + 1, right, target);
        else return this->FindColumn (source, left, middle - 1, target);
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size(), column = matrix[0].size();
        int indexer = this->FindColumn (matrix, 0, row - 1, target);

        if (indexer < 0) indexer = 0;

        return this->BinarySearch (matrix[indexer], 0, column - 1, target);
    }
};