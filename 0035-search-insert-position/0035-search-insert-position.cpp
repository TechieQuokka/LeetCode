class Solution {
private:
    int BinarySearch (vector<int>& source, int left, int right, int target) {

        if (left > right) return left;

        int middle = (left + right) / 2;
        if (source[middle] == target) return middle;
        else if (source[middle] < target) return this->BinarySearch (source, middle + 1, right, target);
        else return this->BinarySearch (source, left, middle - 1, target);
    }

public:
    int searchInsert(vector<int>& nums, int target) {
        
        return this->BinarySearch (nums, 0, nums.size() - 1, target);
    }
};