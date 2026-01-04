class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        if (nums.empty()) return { -1, -1 };
        
        int start = binary_search (nums, 0, nums.size() - 1, target, +[](int a, int b) { return a >= b; });
        int end =   binary_search (nums, 0, nums.size() - 1, target, +[](int a, int b) { return a > b; }) - 1;

        if (start >= nums.size() || end < 0 || nums[start] != target) return { -1, -1 };
        return {start, end};
    }

private:
    int binary_search (vector<int>& source, int left, int right, int target, bool (*compare) (int, int)) {

        if (left > right) return left;

        int middle = left + (right - left) / 2;
        if (compare (source[middle], target)) return binary_search (source, left, middle - 1, target, compare);
        else return binary_search (source, middle + 1, right, target, compare);
    }
};