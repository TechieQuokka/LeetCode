class Solution {
public:

    int BinarySearch (vector<int>& source, int left, int right, int target) {

        if (left > right) return -1;

        int middle = (left + right) / 2;
        if (source[middle] == target) return middle;
        else if (source[middle] < target) return BinarySearch (source, middle + 1, right, target);
        else return BinarySearch (source, left, middle - 1, target);
    }

    int search(vector<int>& nums, int target) {

        return BinarySearch (nums, 0, nums.size() - 1, target);
    }
};