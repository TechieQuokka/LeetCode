class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        return binary_search (nums, 0, nums.size() - 1, target);
    }

private:
    int binary_search (vector<int>& source, int left, int right, int target) {

        if (left > right) return -1;

        int middle = left + (right - left) / 2;
        if (source[middle] == target) return middle;
        else if (is_sorted(source, left, middle)) {

            if (source[left] <= target && target < source[middle]) {

                return binary_search (source, left, middle - 1, target);
            }
            return binary_search (source, middle + 1, right, target);
        }
        else if (source[middle + 1] <= target && target <= source[right]) {

            return binary_search (source, middle + 1, right, target);
        }
        return binary_search (source, left, middle - 1, target);
    }

    bool is_sorted (vector<int>& source, int start, int end) {

        return source[start] <= source[end];
    }
};