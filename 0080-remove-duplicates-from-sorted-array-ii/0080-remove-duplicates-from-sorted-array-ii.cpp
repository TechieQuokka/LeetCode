class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int pivot = -2147483648;
        int left = 0, right = 0, count = 1;
        int length = nums.size();
        while (right < length) {
            if (count >= 2) {

                while (right < length && pivot >= nums[right]) right++;
                if (right == length) break;
                pivot = nums[right];
                count = 1;
            }
            else if (pivot < nums[right]) {

                pivot = nums[right];
                count = 1;
            }
            else count++;
            nums[left++] = nums[right++];
            display (nums, left, right, count);
        }

        return left;
    }

private:
    void display (vector<int>& nums, int left, int right, int count) {

        printf ("%d | %d, %d) ", count, left - 1, right - 1);
        for (const auto& element : nums) {

            cout << element << " ";
        }
        cout << endl;
        return;
    }
};