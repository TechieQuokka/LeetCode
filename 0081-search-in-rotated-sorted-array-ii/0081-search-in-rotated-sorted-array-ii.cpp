class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        if (nums.size() == 1) return nums[0] == target;
        return findTarget (nums, 0, nums.size() - 1, target);
    }

private:
    bool findTarget (vector<int>& source, int left, int right, int target) {

        if (left > right) return false;

        int middle = left + (right - left) / 2;
        if (source[middle] == target) return true;

        if (source[left] == source[middle] && source[middle] == source[right]) {

            return findTarget (source, left + 1, right - 1, target);
        }

        bool leftSorted = source[left] <= source[middle];
        bool rightSorted = source[middle] <= source[right];
        if (leftSorted && rightSorted) {

            if (target < source[middle]) return findTarget (source, left, middle - 1, target);
            else return findTarget (source, middle + 1, right, target);
        }

        if (leftSorted) {
            if (source[left] <= target && source[middle] > target) return findTarget (source, left, middle - 1, target);
            else return findTarget (source, middle + 1, right, target);
        }

        if (source[middle] < target && source[right] >= target) return findTarget (source, middle + 1, right, target);
        else return findTarget (source, left, middle - 1, target);
    }
};