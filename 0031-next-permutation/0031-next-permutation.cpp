class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int pivot = nums.size() - 2;
        while (pivot >= 0 && nums[pivot] >= nums[pivot + 1]) pivot--;

        if (pivot >= 0) {
            int index = nums.size() - 1;
            while (index >= 0 && nums[index] <= nums[pivot]) {
                index--;
            }
            swap(nums[pivot], nums[index]);
        }
        reverse(nums.begin() + pivot + 1, nums.end());
        return;
    }
};